// Leaders elements are those elements which does not have any element
// greater to it on its RHS

/**
 * An element of array is leader if it is greater than or equal to 
 * all the elements to its right side. 
 * Also, the rightmost element is always a leader. 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> leaders(int arr[], int n){
    vector<int> leaders;
    int curr_max = arr[n-1];
    leaders.push_back(curr_max);
    for(int i = n-2; i >= 0; i--){
        if (arr[i] >= curr_max){
            curr_max = arr[i];
            leaders.push_back(curr_max);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main()
{
   long long t;
   cin >> t;
   while (t--)
   {
       long long n;
       cin >> n;
        
        int a[n];
        
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        vector<int> v = leaders(a, n);
        
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;
   }
}