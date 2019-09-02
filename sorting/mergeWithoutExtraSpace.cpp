#include <bits/stdc++.h> 
using namespace std; 

/* Function to merge two input arrays
arr1[], arr2[]: input arrays
n, m: size of arr1[] and arr2[] respectively */
void merge(int arr1[], int arr2[], int n, int m) ;
int nextGap(int gap);

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i < n; i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0; i < m; i++){
	        cin >> arr2[i];
	    }
	    
	    merge(arr1, arr2, n, m); 
        for (int i = 0; i < n; i++) 
            cout <<  arr1[i] << " "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout <<  arr2[i] << " ";  
	    
	    cout << endl;
	}
	return 0; 
}

/* Function to calculate gap
Every pass gap reduces to ceiling value of dividing by 2 */
int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

/* Examples: {
First Example: a1[] = {10 27 38 43 82}, a2[] = {3 9}
Start with gap = ceiling of n/2 (4):
10 27 38 43 82   3 9 
10 27 38 43 82   3 9
10 3 38 43 82   27 9
10 3 9 43 82   27 38
gap = 2:
10 3 9 43 82   27 38
9 3 10 43 82   27 38
9 3 10 43 82   27 38
9 3 10 43 82   27 38
9 3 10 27 82   43 38
9 3 10 27 38   43 82
gap = 1
9 3 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82
Output : 3 9 10 27 38   43 82
*/

/* The idea is to compare the far away elements rather than adjacent one
For every pass we compute the gap and compare the elements towards the right of the gap
Every pass, the gap reduces to ceiling value of dividing by 2 */

void merge(int arr1[], int arr2[], int n, int m) 
{
    int i, j;
    // initialise gap to n + m
    int gap = n+m;
    
    // we run loop while gap > 0, (giving us time complexity: log(n+m) reducing half everytime)
    for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
    // inner procedure in O(n+m) for every iteration

        // compare the elements in the first array
        for(i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays
        for(j = gap > n ? gap -n : 0; i < n && j < m; i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
                
        if (j < m) {
            // comparing elements in the second array
            for(j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j+gap])
                    swap(arr2[j], arr2[j+gap]);
        }
    }
} 

// Time Complexity: O((n+m)*log(n+m))
// Space Complexity: O(1)

// Company tags: Amdocs, Brocade, Goldman Sachs, Juniper Networks, LinkedIn, Microsoft, Quickr, Snapdeal, Synopsys, Zoho