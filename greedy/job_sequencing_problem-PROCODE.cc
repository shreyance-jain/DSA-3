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

struct cmp{
    bool operator()(Job &j1, Job &j2) {
        return j1.profit > j2.profit;
    }
};


// Prints minimum number of platforms reqquired 
void printJobScheduling(Job arr[], int n) 
{ 
    // sort the jobs in decreasing order of the profits
    sort(arr, arr+n, cmp());
    
    int picked[n];
    for(int i = 0; i < n; i++)
        picked[i] = -1;
    
    // pick the first job
    int count = 0;
    int profit = 0;
    
    // pick the next jobs with max profit and palce them at latest available positions
    for(int i = 0; i < n; i++)
        for(int j = arr[i].dead > n ? n-1: arr[i].dead-1; j >=0; j--) // can be better written as
        //for (int j=min(n, arr[i].dead)-1; j>=0; j--)
            if (picked[j] == -1) {
                picked[j] = i;
                count++;
                profit += arr[i].profit;
                break;
            }
    
    cout << count << " " << profit << endl;
} 
// Note: We can keep an additional result[] to store jobs sequentially


// PRO CODE
// The condition for choosing the index can be better written as
/*
for (int j=min(n, arr[i].dead)-1; j>=0; j--)
*/