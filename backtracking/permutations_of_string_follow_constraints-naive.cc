/* 
Generate all permutations of a string that follow given constraints

Given a string, generate all permutations of it that do not contain ‘B’ after ‘A’,
i.e., the string should not contain “AB” as a substring.

Examples:

Input : str = “ABC”
Output : ACB, BAC, BCA, CBA
Out of 6 permutations of “ABC”, 4 follow the given constraint and 2 (“ABC” and “CAB”) do not follow.

Input : str = “BCD”
Output : BCD, BDC, CDB, CBD, DCB, DBC
 */

#include <iostream>
#include <string>
using namespace std;

void permute(string str);

int main() {
  int t;
  cin >> t;
  while(t--) {
    string str;
    cin >> str;
    permute(str);
    cout << endl;
  }
}

/* Approach:
A Naive and simple solution is to generate all permutations.
For every permutation check if it follows the constraint
 */

void permuteUtil(string str, int l, int r) {
  if (l == r) {
    // check if it follow the constraint then print it
    if (str.find("AB") == string::npos)
      cout << str << " ";
    return;
  }
  for(int i = l ; i <= r; i++) {
    // we try every element for given l
    swap(str[l], str[i]);
    // recur l + 1
    permuteUtil(str, l+1, r);
    // swap and make the string same as above
    // to try the next element at position l
    swap(str[l], str[i]);
  }
}

void permute(string str) {
  int n = str.length();
  permuteUtil(str, 0, n-1);
}
