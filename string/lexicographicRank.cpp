/* 
Lexicographic Rank Of A String

Problems

You are given a string S of lowercase characters,
find the rank of the string amongst its permutations when sorted lexicographically.
Return 0 if the characters are repeated in the string.
Note: Return the rank%1000000007 as answer as rank might overflow.

Input Format:
The first line of input contains an integer T denoting the number of test cases.
Each test case consist of a string S in 'lowercase' only in a separate line.

Output Format:
For each testcase, in a new line, print the rank of the string amongst its lexicographically-sorted-permutations.

Constraints:
1 ≤ T ≤ 50
1 ≤ |S| ≤ 15

Example:
Input:
3
abc
acb
caa
cba
string
Output:
1
2
0
6
598

Explanation:
Testcase2:
Input : 'acb'
Output : 2
The lexicographically-sorted permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
You can clearly see that acb occurs at position 2 in the permutations.
 */

#include<bits/stdc++.h>
using namespace std;

int findRank(string str);

// driver code
int main()
{
    string S;
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>S;
    cout<<findRank(S)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/

int fact(int n) {
    return (n == 0 || n == 1) ? 1 : n * fact(n-1);
}


/*
One simple solution is to initialize rank as 1, generate all permutations in lexicographic order.
After generating a permutation, check if the generated permutation is same as given string, if same,
then return rank, if not, then increment the rank by 1.
The time complexity of this solution will be exponential in worst case.
Following is an efficient solution.

the idea here is to calculate all the string lexically smaller than the
given string and add 1 to it to give its lexical rank among its permutations

Let the given string be “STRING”. In the input string, ‘S’ is the first character.
There are total 6 characters and 4 of them are smaller than ‘S’.
So there can be 4 * 5! smaller strings where first character is smaller than ‘S’, like following

R X X X X X
I X X X X X
N X X X X X
G X X X X X

Now let us Fix S’ and find the smaller strings starting with ‘S’.

Repeat the same process for T, rank is 4*5! + 4*4! +…

Now fix T and repeat the same process for R, rank is 4*5! + 4*4! + 3*3! +…

Now fix R and repeat the same process for I, rank is 4*5! + 4*4! + 3*3! + 1*2! +…

Now fix I and repeat the same process for N, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! +…

Now fix N and repeat the same process for G, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0!

Rank = 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0! = 597
 */
int findRank(string str) 
{
    // the idea here is to calculate all the string lexically smaller than the
    // given string and add 1 to it to give its lexical rank among its permutations
    int n = str.length();
    int count[256] = {0};
    int rank = 1;
    int mul = fact(n);
    
    for(int i = 0; i < n; i++) {
        if (count[str[i]] > 0)
            return 0;
        count[str[i]]++;
    }
    
    // store the cumulative counts so we can have O(1) access to no of characters
    // that are smaller than the current character
    for(int i = 1; i < 256; i++)
        count[i] = count[i] + count[i-1];
    
    for(int i = 0; i < n; i++) {
        mul = mul / (n-i);
        rank = rank + count[str[i] - 1]*mul;
        
        for(int j = str[i]; j < 256; j++)
            count[j]--;
    }
    return rank;
}
