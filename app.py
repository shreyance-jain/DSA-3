from ..base import Base
from .adapter import InputAdapter
from lib import Logger
from models.feed import Feed
from models.connection import Connection
from googleads import adwords
from werkzeug.exceptions import BadRequest
import boto3
import asyncio
import credstash
from googleads import oauth2
import json
import asyncio
import os
from flask import jsonify
import io
import sys
import gzip

class Fetch(Base):
    def get(self):
        reqBody = InputAdapter().parseGetRequest()
        feed = {"metadata":{"customerId":"1234565432","customFromDate":"null","connectionName":"5may","dateFilter":"90days","tableName":"ad_performance"},"destinations":[{"type":"spark","applicable":"false"},{"type":"redshift","applicable":"true","firstApplicableAt":"1588663593271"}],"schema":[{"sourceDataType":"long","peakDataType":"numeric","columnName":"Id","dataType":"numeric(10,0)"},{"sourceDataType":"long","peakDataType":"numeric","columnName":"AdGroupId","dataType":"numeric(10,0)"},{"sourceDataType":"string","peakDataType":"string","columnName":"AdGroupName","dataType":"varchar(65535)"},{"sourceDataType":"enum","peakDataType":"string","columnName":"AdGroupStatus","dataType":"varchar(65535)"},{"sourceDataType":"long","peakDataType":"numeric","columnName":"CampaignId","dataType":"numeric(10,0)"},{"sourceDataType":"enum","peakDataType":"string","columnName":"AdType","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"CampaignName","dataType":"varchar(65535)"},{"sourceDataType":"enum","peakDataType":"string","columnName":"CampaignStatus","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"Headline","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"HeadlinePart1","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"HeadlinePart2","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"ImageAdUrl","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"LongHeadline","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"ShortHeadline","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"DisplayUrl","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"Description","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"Description1","dataType":"varchar(65535)"},{"sourceDataType":"string","peakDataType":"string","columnName":"Description2","dataType":"varchar(65535)"},{"sourceDataType":"json","peakDataType":"string","columnName":"CreativeFinalMobileUrls","dataType":"varchar(65535)"},{"sourceDataType":"double","peakDataType":"float","columnName":"Conversions","dataType":"float"},{"sourceDataType":"date","peakDataType":"date","columnName":"Date","dataType":"date"}],"frequency":"00 00 * * 0,1,2,4,5,6","status":"1","feedId":"694074a3-6368-4e04-a442-5afc84d3ec67","createdAt":"1588663593271","frequencyType":"basic","projectName":"Integration","createdBy":"sukhbir.singh@peak.ai","feedType":"10","dataFormat":{"separator":"comma","fileType":"csv"},"sourceTable":"googleads.test77","tenant":"integration2020","feedName":"test77"}
        # logger = Logger('Fetch', 'adwords-fetch', reqBody['feedId'])
        # try:
        #     feed = Feed().get(reqBody['tenant'], reqBody['feedId'])
        # except Exception as e:
        #     raise BadRequest("Invalid Feed Id")
        self.fetch_and_upload_to_s3_new(feed['tenant'], feed, 'connection')

    def gzip_str(self, string_):
        out = io.BytesIO()

        with gzip.GzipFile(fileobj=out, mode='w') as fo:
            fo.write(string_.encode())

        bytes_obj = out.getvalue()
        return bytes_obj

    def fetch_and_upload_to_s3(self, tenant, feed, connection):
        # credentialsName = tenant + connection['connectionId']
        # kms = boto3.client('kms')
        # secret = credstash.getSecret(
        #     name=credentialsName,
        #     table='kilimanjaro-latest-credentials',
        #     kms=kms,
        #     context={ 'access': tenant}
        #     )
        print('beginning work')
        refreshToken = '1//04fBw5VSJ7oF5CgYIARAAGAQSNwF-L9IrCE53bDpnv8652TDVTEFHhhkx7mNBC-nXOfSA6I_Qp4pJqAkfDMboUlIekks9UjCiMOQ'

        clientId = '60914815831-2t42edddggbns2s6g7i9iurc4t9a96i6.apps.googleusercontent.com'
        clientSecret = 'oGP-uoA1Oc9HVtGeF8vtIYTr'
        developerToken =  '0qPN98uVQ0jU6ZWPcfhIdw'
        clientCustomerId = '311-101-7656'

        oauth2_client = oauth2.GoogleRefreshTokenClient(clientId, clientSecret, refreshToken)

        adwords_client = adwords.AdWordsClient(developerToken, oauth2_client, '', client_customer_id=clientCustomerId)

        report_downloader = adwords_client.GetReportDownloader(version='v201809')
        report = {
            'reportName': feed['metadata']['tableName'],
            'dateRangeType': 'LAST_7_DAYS', # feed['metadata']['dateFilter'],
            'reportType': 'AD_PERFORMANCE_REPORT', # TODO: from mapping
            'downloadFormat': 'CSV',
            'selector': {
                'fields': list(map(lambda col: col['columnName'], feed['schema']))
            }
        }

        print(report['reportName'])

        stream_data = report_downloader.DownloadReportAsStream(
            report, skip_report_header=False, skip_column_header=False,
            skip_report_summary=False, include_zero_impressions=True)

        # s3 = boto3.client('s3')

        # s3.upload_fileobj(stream_data, tenant + '/raw', feed['feedId'])
        # stream_data.close()
        print('streaming done')

    def fetch_and_upload_to_s3_new(self, tenant, feed, connection):
        # credentialsName = tenant + connection['connectionId']
        # kms = boto3.client('kms')
        # secret = credstash.getSecret(
        #     name=credentialsName,
        #     table='kilimanjaro-latest-credentials',
        #     kms=kms,
        #     context={ 'access': tenant}
        #     )
        print('beginning my work')
        refreshToken = '1//04fBw5VSJ7oF5CgYIARAAGAQSNwF-L9IrCE53bDpnv8652TDVTEFHhhkx7mNBC-nXOfSA6I_Qp4pJqAkfDMboUlIekks9UjCiMOQ'

        clientId = '60914815831-2t42edddggbns2s6g7i9iurc4t9a96i6.apps.googleusercontent.com'
        clientSecret = 'oGP-uoA1Oc9HVtGeF8vtIYTr'
        developerToken =  '0qPN98uVQ0jU6ZWPcfhIdw'
        clientCustomerId = '311-101-7656'

        oauth2_client = oauth2.GoogleRefreshTokenClient(clientId, clientSecret, refreshToken)

        adwords_client = adwords.AdWordsClient(developerToken, oauth2_client, '', client_customer_id=clientCustomerId)

        report_downloader = adwords_client.GetReportDownloader(version='v201809')
        # Create report query.
        # report_query = (adwords.ReportQueryBuilder()
        #           .Select('CampaignId', 'AdGroupId', 'Id', 'AdGroupName')
        #           .From('AD_PERFORMANCE_REPORT')
        #           .Where('Status').In('ENABLED', 'PAUSED')
        #           .During('LAST_7_DAYS')
        #           .Limit('10')
        #           .Build())
        report = {
            'reportName': feed['metadata']['tableName'],
            'dateRangeType': 'LAST_7_DAYS', # feed['metadata']['dateFilter'],
            'reportType': 'AD_PERFORMANCE_REPORT', # TODO: from mapping
            'downloadFormat': 'CSV',
            'selector': {
                'fields': list(map(lambda col: col['columnName'], feed['schema'])),
            },
        }

        stream_data = report_downloader.DownloadReportAsStream(
            report, skip_report_header=False, skip_column_header=False,
            skip_report_summary=False, include_zero_impressions=True)

        report_data = io.StringIO()
        # print(stream_data)
        # print("reading chunk")
        CHUNK_SIZE = 16 * 1024
        chunk = stream_data.read(CHUNK_SIZE)
        report_data.write(chunk.decode() if sys.version_info[0] == 3
                        and getattr(report_data, 'mode', 'w') == 'w' else chunk)
        d = report_data.getvalue()
        da = json.dumps(d)
        

        data = self.gzip_str(da)
        data2 = gzip.compress(chunk)
        # print('reading done')


        s3 = boto3.client('s3')

        s3.put_object(Bucket='kilimanjaro-latest-datalake', Key=tenant + '/sourceSample/' + feed['feedId'] + '/sample.gz', Body=data)
        stream_data.close()
        print('streaming done')
