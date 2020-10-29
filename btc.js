const request = require('async-request');
const bigi = require('bigi');
const buffer = require('buffer');
const bitcoin = require('bitcoinjs-lib');


const wallet1 = {
  private: 'da6a1b1f5b911888dafb42e7f6e96ac79777a842dfd4f99727d34b0a24883dd3',
  public: '038c1e8dd52b3ba4e945f044f04af1b8ef64bae68e2d3247d3c3149d308ec36a22',
  address: 'mwx4Awh9rRMCzceLCj3xoWFNNRMK6qk4un',
  wif: 'cUuGfN3ThWWfFR7dvim9HrAWdYn1eaaLGtchqZyr4KG4aYB283Kv',
};

const wallet2 = {
  private: '9f075ce7b4c03ed587c074fb6ab3db511f7ea5149103a3b74a1f52d8487c9f0d',
  public: '037252e44d605f0db1fe8d8b7e1d7d26657e4e35ff3b8a38d6b3ee6c904320e065',
  address: 'n4RvdpVafZXQBcFEZZag2sz1CKXELzat88',
  wif: 'cSuqFhNufAZwEKYcpMpcRXZDvc2wvyTUQR2TjYexcC7cFgVys6dg',
};

const keys = bitcoin.ECPair.fromPrivateKey(Buffer.from(wallet1.private, 'hex'));

const newtx = {
  inputs: [{addresses: [wallet1.address]}],
  outputs: [{addresses: [wallet2.address], value: 10000}],
};

const hello = async () => {
  const response = await request('https://api.blockcypher.com/v1/btc/test3/txs/new', {method: 'POST', data: JSON.stringify(newtx)});
  const tmptx = JSON.parse(response.body);
  tmptx.pubkeys = [];
  tmptx.signatures = tmptx.tosign.map((tosign, _n) => {
    tmptx.pubkeys.push(keys.publicKey.toString('hex'));
    const signature = keys.sign(Buffer.from(tosign, 'hex'));
    const encodedSignature = bitcoin.script.signature.encode(signature, bitcoin.Transaction.SIGHASH_ALL);
    const hexStr = encodedSignature.toString('hex').slice(0, -2);
    return hexStr;
  });
  //   console.log('response ', response);
  //   console.log('temptx ', tmptx);
  //   console.log('check to sign');
  //   console.log(tmptx.tosign);
  const response2 = await request('https://api.blockcypher.com/v1/btc/test3/txs/send', {method: 'POST', data: JSON.stringify(tmptx)});
  console.log('response2 ', response2);
  const finaltx = JSON.parse(response2.body);
  console.log('finaltx ', finaltx);
};

hello().then(() => console.log('Done!')).catch(e => console.log(e));

/*
response2  { statusCode: 201,
  headers:
   { date: 'Thu, 29 Oct 2020 12:57:46 GMT',
     'content-type': 'application/json',
     'content-length': '1653',
     connection: 'close',
     'set-cookie':
      [ '__cfduid=d5faa357941d53a1b329a03cd447517971603976265; expires=Sat, 28-Nov-20 12:57:45 GMT; path=/; domain=.blockcypher.com; HttpOnly; SameSite=Lax' ],
     'access-control-allow-headers': 'Origin, X-Requested-With, Content-Type, Accept',
     'access-control-allow-methods': 'GET, POST, PUT, DELETE',
     'access-control-allow-origin': '*',
     'x-ratelimit-remaining': '84',
     'cf-cache-status': 'DYNAMIC',
     'cf-request-id': '06160897ba0000de250203b000000001',
     'expect-ct':
      'max-age=604800, report-uri="https://report-uri.cloudflare.com/cdn-cgi/beacon/expect-ct"',
     server: 'cloudflare',
     'cf-ray': '5e9d106c5c14de25-BOM' },
  body:
   '{\n  "tx": {\n    "block_height": -1,\n    "block_index": -1,\n    "hash": "f2ba10e6120f23e1627ffd375d03daa0b533f839764b2c1b3d78a84c9ecf11de",\n    "addresses": [\n      "mwx4Awh9rRMCzceLCj3xoWFNNRMK6qk4un",\n      "n4RvdpVafZXQBcFEZZag2sz1CKXELzat88"\n    ],\n    "total": 936600,\n    "fees": 63400,\n    "size": 225,\n    "preference": "high",\n    "relayed_by": "49.36.149.101",\n    "received": "2020-10-29T12:57:46.403337742Z",\n    "ver": 1,\n    "double_spend": false,\n    "vin_sz": 1,\n    "vout_sz": 2,\n    "confirmations": 0,\n    "inputs": [\n      {\n        "prev_hash": "f5ab52ca5d3330bfc0e72d16202eaa656da69d01acd6fb8f4793b4eae78f409b",\n        "output_index": 0,\n        "script": "473044022056e537fbfbe8bffbe6565a0b458efef3d729f990b5de4a789741f3ba3b76384902202bc7f8a525df9ddecef55b372a0b0cf6e5eb99efa6b082a560502aca635224a30121038c1e8dd52b3ba4e945f044f04af1b8ef64bae68e2d3247d3c3149d308ec36a22",\n        "output_value": 1000000,\n        "sequence": 4294967295,\n        "addresses": [\n          "mwx4Awh9rRMCzceLCj3xoWFNNRMK6qk4un"\n        ],\n        "script_type": "pay-to-pubkey-hash",\n        "age": 1865485\n      }\n    ],\n    "outputs": [\n      {\n        "value": 10000,\n        "script": "76a914fb576d9cfa475653190b52760c931d1eba45775288ac",\n        "addresses": [\n          "n4RvdpVafZXQBcFEZZag2sz1CKXELzat88"\n        ],\n        "script_type": "pay-to-pubkey-hash"\n      },\n      {\n        "value": 926600,\n        "script": "76a914b441515b535275bed67c7c4432fd84bac0863e2188ac",\n        "addresses": [\n          "mwx4Awh9rRMCzceLCj3xoWFNNRMK6qk4un"\n        ],\n        "script_type": "pay-to-pubkey-hash"\n      }\n    ]\n  },\n  "tosign": [\n    ""\n  ]\n}' }
finaltx  {
  "tx": {
    "block_height": -1,
    "block_index": -1,
    "hash": "f2ba10e6120f23e1627ffd375d03daa0b533f839764b2c1b3d78a84c9ecf11de",
    "addresses": [
      "mwx4Awh9rRMCzceLCj3xoWFNNRMK6qk4un",
      "n4RvdpVafZXQBcFEZZag2sz1CKXELzat88"
    ],
    "total": 936600,
    "fees": 63400,
    "size": 225,
    "preference": "high",
    "relayed_by": "49.36.149.101",
    "received": "2020-10-29T12:57:46.403337742Z",
    "ver": 1,
    "double_spend": false,
    "vin_sz": 1,
    "vout_sz": 2,
    "confirmations": 0,
    "inputs": [
      {
        "prev_hash": "f5ab52ca5d3330bfc0e72d16202eaa656da69d01acd6fb8f4793b4eae78f409b",
        "output_index": 0,
        "script": "473044022056e537fbfbe8bffbe6565a0b458efef3d729f990b5de4a789741f3ba3b76384902202bc7f8a525df9ddecef55b372a0b0cf6e5eb99efa6b082a560502aca635224a30121038c1e8dd52b3ba4e945f044f04af1b8ef64bae68e2d3247d3c3149d308ec36a22",
        "output_value": 1000000,
        "sequence": 4294967295,
        "addresses": [
          "mwx4Awh9rRMCzceLCj3xoWFNNRMK6qk4un"
        ],
        "script_type": "pay-to-pubkey-hash",
        "age": 1865485
      }
    ],
    "outputs": [
      {
        "value": 10000,
        "script": "76a914fb576d9cfa475653190b52760c931d1eba45775288ac",
        "addresses": [
          "n4RvdpVafZXQBcFEZZag2sz1CKXELzat88"
        ],
        "script_type": "pay-to-pubkey-hash"
      },
      {
        "value": 926600,
        "script": "76a914b441515b535275bed67c7c4432fd84bac0863e2188ac",
        "addresses": [
          "mwx4Awh9rRMCzceLCj3xoWFNNRMK6qk4un"
        ],
        "script_type": "pay-to-pubkey-hash"
      }
    ]
  },
  "tosign": [
    ""
  ]
}
*/
