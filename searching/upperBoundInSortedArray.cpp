/* Upper-bound or ciel of an element in sorted array */
#include <bits/stdc++.h>

using namespace std;

/* Approch:
The array is sorted,
- we can find the upper bound by linear traversal O(n)
Below we use the binary seach algorithm to keep track of upper bound (ciel), whenever arr[mid] > x
similarly we can keep track of lower bound (floor) whenever arr[mid] < x
O(logn)
*/

int upperBound(vector<long long> v, long long n, long long x) {
  long long start = 0, end = n - 1, ans = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == x)
      return mid;
    if (v[mid] < x)
      start = start + 1;
    else {
      ans = mid;
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  long long t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;
    long long x;
    cin >> x;

    vector<long long> v;

    for(long long i = 0; i < n; i++) {
      long long temp;
      cin >> temp;
      v.push_back(temp);
    }

    cout << v[upperBound(v, n, x)] << endl;
  }
  return 0;
}