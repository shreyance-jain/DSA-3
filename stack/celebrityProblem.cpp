/* 
The Celebrity Problem

Problems

You are in a party of N people, where only one person is known to everyone.
Such a person may be present in the party, if yes,
(s)he doesn’t know anyone in the party.
Your task is to find the stranger (celebrity) in party.
You will be given a square matrix M[][] where
if an element of row i and column j  is set to 1 it means ith person knows jth person.
You need to complete the function getId() which
finds the id of the celebrity if present else return -1.
The function getId() takes two arguments, the square matrix M and its size N.

Note: Expected time complexity is O(N) with constant extra space.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases follow.
Each test case consist of 2 lines.
The first line of each test case contains a number denoting the size of the matrix M.
Then in the next line are space separated values of the matrix M.

Output:
For each test case output will be the id of the celebrity if present (0 based index). Else -1 will be printed.

Constraints:
1 <= T <= 50
2 <= N <= 501
0 <= M[][] <= 1

Example:
Input (To be used only for expected output) :
2
3
0 1 0 0 0 0 0 1 0
2
0 1 1 0

Output :
1
-1

Explanation :
For the above test case the matrix will look like
0 1 0 
0 0 0
0 1 0
Here,  the celebrity is the person with index 1 ie id 1 
 */


#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int getId2Pointers(int M[MAX][MAX], int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;
        cout<<getId2Pointers(M,N)<<endl;
    }
}

/* 
We have following observation based on elimination technique (Refer Polya’s How to Solve It book).
    If A knows B, then A can’t be celebrity. Discard A, and B may be celebrity.
    If A doesn’t know B, then B can’t be celebrity. Discard B, and A may be celebrity.
    Repeat above two steps till we left with only one person.
    Ensure the remained person is celebrity.
 */
/*
We can use stack to verity celebrity.

-Push all the celebrities into a stack.
-Pop off top two persons from the stack, discard one person based on return status of HaveAcquaintance(A, B).
-Push the remained person onto stack.
-Repeat step 2 and 3 until only one person remains in the stack.
-Check the remained person in stack doesn’t have acquaintance with anyone else.
 */
int getId(int M[MAX][MAX], int n)
{
    // here handle trivial case
    // when n = 2
    stack<int> st;

    int c; //celebrity
    
    for(int i = 0; i < n; i++) {
        st.push(i);
    }
    
    // extract top 2
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    
    // find a potential celebrity
    while(st.size() > 1) {
        if (M[a][b]) {
            a = st.top();
            st.pop();
        } else {
            b = st.top();
            st.pop();
        }
    }
    
    // potential candidate
    c = st.top();
    st.top();

    // last candidate was not examined
    // needs extra comparison (optimize)
    if (M[c][b]) {
        c = b;
    }
    if (M[c][a]) {
        c = a;
    }
    
    // check if c is celebrity or not
    for(int i = 0; i < n; i++) {
        // if any person doesn't know 'a' or 'a' doesn't know any person return -1
        if (i != c && (!M[i][c] || M[c][i]))
            return -1;
    }
    return c;
}

/* The idea is to use two pointers, one from start and one from end
Assume that start person is A and end person in B
If A knows B, then A is not celebrity
Else B is not celebrity
We will find a celebrity candidate at the end of the loop
Finally we check if possible candidate is celeb or not */
int getId2Pointers(int M[MAX][MAX], int n) {
    int a = 0;
    int b = n-1;
    while(a < b) {
        if (M[a][b]) {
            a++;
        } else {
            b--;
        }
    }
    for(int i = 0; i < n; i++) {
        if (i != a && (M[a][i] || !M[i][a]))
            return -1;
    }
    return a;
}

// Company Tags: Amazon, Fab.com, Flipkart, Google, Microsoft, One97, United Health Group, Zoho