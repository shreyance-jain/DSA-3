#include <iostream>

using namespace std;

// Time Complexity: The below algorithm runs in O(N), 
// where N is the number of elements present in the array

// Space Complexity: There is no extra space used however
// the internal stack takes O(N) extra space for recursive calls

int search(int arr[],int l,  int r, int key) {

    if(r < 0) return -1;

    if (arr[l] == key) {
        return l;
    } else if (arr[r] == key){ 
        return r;
    } else {
        return search(arr, l+1, r-1, key);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 3;
    int result = search(arr, 0, n-1, key);
    cout << "result: found at: " << result << endl;
}