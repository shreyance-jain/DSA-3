/* 
ALL PERMUTATIONS OF A GIVEN STRING

A permutation, also called an arrangement number or order, is an rearrangement
of the elements of an ordered list S into a one-to-one correspondence with S itself.
A string of lenght n has n! permutation

Below are permutations of string ABC
ABC ACB BAC BCA CBA CAB

HERE IS A SOLUTION THAT IS USED AS BASIS IN BACKTRACKING
 */

#include <iostream>
#include <string>

using namespace std;

void permute(string str, int l, int r) {
  if (l == r) {
    cout << str <<  endl;
    return;
  }
  // FIX ALL CHARACTERS ONE BY ONE FOR POSITION L
  for(int i = l; i <= r; i++) { // permutations made
    // swap
    swap(str[l], str[i]);
    // recur
    permute(str, l+1, r);
    // backtrack
    swap(str[l], str[i]);
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string str;
    cin >> str;
    int n = str.length();
    permute(str, 0, n-1);
    cout << endl;
  }
}

/* NOTE:  The above solution print duplicate premutations if there are 
repeating characters in input string*/

// Algorithm Paradigm: Backtracking

// Time Complexity: O(n*n!) Note that there are n! premutations
// and it takes O(n) to print a permutation

