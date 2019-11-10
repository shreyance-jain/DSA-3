/* 
The Modified String
   
Problem Statement

Ishaan is playing with strings these days. He has found a new string. He wants to modify it as per the following rules :

-The string should not have three consecutive same characters (Refer example for explanation).
-He can add any number of characters anywhere in the string.
Find the minimum number of characters which Ishaan must insert in the string.

Input Format: 
First line of input contains a single integer T denoting the number of test cases.
The only line of each test case contains a string S consisting of lowercase English Alphabets.

Output Format: 
For each test case, in a new line,  print the required answer in a new line.

Your Task:
This is a function problem. You only need to complete the function modified that returns the answer.

Constraints : 
1 <= T <= 200
1 <= Length of S <= 103

Example : 
Input : 
3
aabbbcc
aaaaa
abcddee
Output : 
1
2
0

Explanation : 
Case 1 : 
aabbbcc
3 b's occur consecutively, we add a 'd',
aabbdbcc

Case 2 : 
aaaaa
5 a's occur consecutively, we need to add 2 'b',
aababaa

Case 3 : 
abcddee
No character occurs 3 times, so no need to add anything.
 */


#include<bits/stdc++.h>
using namespace std;

int modified(string a);

// driver code
int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        cout<<modified(a)<<endl;
    }
    return 0;
}

/* 
Logic here is very simple, we traverse the input string and whenever we encounter 3 consecutive characters to be same
we can simply add one to count and skip the next character from traversing, because we assume out of
three consecutive characters we have added a new character after two repeating characters and keep on checking the same
till the end of string

One another solution is through finding no of repeating characters and for every consecutive repeating characeters
add n-1/2 to ans where n is no of consecutive repeating characters
 */
int modified (string a){
    int n = a.length();
    int count = 0;
    
    for(int i = 0; i < n - 2; i++) {
        if (a[i] == a[i+1] && a[i+1] == a[i+2]) {
            count += 1;
            i++;
        }
    }
    return count;
}

/* 
int modified(string a){
    int ans, same;
    ans=0;
    same=1;
    
    // check for any three consecutive same characters
    // if found, then increment the count of characters to be added
    for(int i=1;a[i];i++){
        if(a[i]==a[i-1]){
            same++;
        }
        else{
            ans+=(same-1)/2;
            same=1;
        }
    }
    
    ans += (same-1)/2;
    return ans;
}
 */

// Time Complexity: O(n)
// Aux Space Complexity: O(1)