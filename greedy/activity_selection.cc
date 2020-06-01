/* 
Activity Selection

Difficulty: Easy

Problem Statements

Given N activities with their start and finish times.
Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
First line is N number of activities then second line contains N numbers which are starting time of activies.
Third line contains N finishing time of activities.

Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.

Constraints:
1 <= T <= 50
1 <= N <= 105
1 <= start[i] <= end[i] <= 105

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4
 */

#include<bits/stdc++.h>
using namespace std;

int activitySelection(int [], int [], int);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        
        cout << activitySelection(start, end, n) << endl;
    }
    return 0;
}


/* 
Approach: Pick the next activity whose finish time is least among the remaining
activities and the start time is more than or equal to finish time of
previously selected activity.

Sort the activities according to their finishing time so that one can always
consider the next activity as minimum finishing time activity.
 */
struct cmp{
    bool operator()(pair<int, int> &a1, pair<int, int> &a2) {
        if (a1.second == a2.second)
            return a1.first < a2.first;
        return a1.second < a2.second;
    }
};

int activitySelection(int start[], int end[], int n){
    pair<int, int> activity[n];
    for(int i = 0; i < n; i++)
        activity[i] = {start[i], end[i]};
    
    // sort actvity with increasing order of finish time
    sort(activity, activity+n, cmp());
    
    // pick the first activity from the sorted array
    int last_picked = 0;
    int picked_count = 1;
    
    int current = 1;
    while(current < n) {
        if (activity[current].first >= activity[last_picked].second){
            picked_count++;
            last_picked = current;
        }
        current++;
    }
    return picked_count;
} // see PRO CODE below

// PRO CODE

/* Instead of too directly/stricly following the explanation video
we can create the activity array with first item of pair as end time 
and the second item of the pair as start time and could have avoided
wrting the custom comparator */

// Company Tags: Facebook, Morgan Stanley
