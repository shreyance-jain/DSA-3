/* 
Job Sequencing Problem

Difficulty: Medium

Problems

Given a set of N jobs where each job i has a deadline and profit associated to it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit if and only if the job is completed by its deadline.
The task is to find the maximum profit and the number of jobs done.

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case consist of an integer N in first line denoting the number of jobs
and the next line consist of Job id, Deadline and the Profit associated to that Job.

Output:
Output the number of jobs done and the maximum profit.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500

Example:
Input:
2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

Output:
2 60
2 127

Explanation:
Testcase 1: 2 jobs can be done with maximum profit of 60.
 */


// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

void printJobScheduling(Job arr[], int n);

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        printJobScheduling(arr, n);
    }
	return 0; 
}


/* 
1. Sort all jobs in decreasing order of profits
2. Initialise the result sequence as first job in sorted array
3. Do following for remaining n-1 jobs
....a) If the current job can fit in the current job sequence
    without missing the deadline, add current job to the result
    Else ingnore the current job
 */
// comparator to sorts the job in decreasing order of profits
struct cmp{
    bool operator()(Job &j1, Job &j2) {
        if (j1.profit == j2.profit)
            return j1.dead > j2.dead;
        return j1.profit > j2.profit;
    }
};


void printJobScheduling(Job arr[], int n) 
{ 
    // sort the jobs in decreasing order of the profits
    sort(arr, arr+n, cmp());
    
    // find the job with max deadline
    // we will use this is as the size of bar graph of jobs time axis
    int max_deadline = INT_MIN;
    for(int i = 0; i < n; i++)
        if (arr[i].dead > max_deadline)
            max_deadline = arr[i].dead;
    
    int picked[max_deadline];
    for(int i = 0; i < max_deadline; i++)
        picked[i] = -1;
    
    // pick the first job
    picked[arr[0].dead-1] = 0;
    int count = 1;
    int profit = arr[0].profit;
    
    // pick the next jobs with max profit and palce them at latest available positions
    for(int i = 1; i < n; i++) {
        int deadline = arr[i].dead;
        int preferred = deadline - 1;
        while(preferred >= 0) {
            if (picked[preferred] == -1) {
                picked[preferred] = i;
                count++;
                profit += arr[i].profit;
                break;
            }
            else
                preferred--;
        }
    }
    
    cout << count << " " << profit << endl;
} // PRO CODE

/* PRO CODE is I found out the max deadline job for the test case when
the deadline of the job would be greater than n
Suppose if we have 2 jobs and deadline of one of the job is very big and
we would end up wasting a lot of space for n(here 2) jobs 

So to avoid that we will keep the picked array above of size n only
and begin the index from last if the deadline is greater than n

And can also avoid the equal profit condition check in comparator as it is
not required
*/

// COMPANY TAGS: Accolite
