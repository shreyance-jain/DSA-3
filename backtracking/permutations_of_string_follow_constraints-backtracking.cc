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

/* Efficient Approach:
An efficient solution is to use BACKTRACKING. We cut down the recursion tree whenever we see
that substing "AB" is formed.
How do we do this?
we add a isSafe() function.
Before doing a swap we check if previous character is 'A' and current character is 'B'

We also take care of an edge case explicitly which is required
when last two characters are "BA". We don't want them to be swapped
and become "AB" 
*/

bool isSafe(string str, int i, int l, int r) {
  // if previous character was 'A' and character is 'B'
  // then do not proceed and cut down the recursion tree
  if (l-1 >= 0 && str[l-1] == 'A' && str[i] == 'B')
    return false;
  // This condition is explicitly required for the cases
  // when last two characters are "BA". We do not want
  // them to swapped and becomt "AB"
  if (l+1 == r && str[l] == 'B' && str[i] == 'A')
    return false;
  // else safe move
  return true;
}

void permuteUtil(string str, int l, int r) {
  // we reach here only when the permutation is valid
  if (l == r) {
      cout << str << " ";
    return;
  }
  // FIX ALL THE CHARACTERS ONE BY ONE
  for(int i = l ; i <= r; i++) {
    // fix str[i] only if it is a valid move
    if (isSafe(str, i, l, r)) {
      // we try every element for given l
      swap(str[l], str[i]);
      // recur l + 1
      permuteUtil(str, l+1, r);
      // swap and make the string same as above
      // to try the next element at position l
      swap(str[l], str[i]);
    }
  }
}

void permute(string str) {
  int n = str.length();
  permuteUtil(str, 0, n-1);
}
