/* 
Delete middle element of a stack

Problem Statement

Given a stack with push(), pop(), empty() operations,
delete middle of it without using any additional data structure.
Middle: ceil(size_of_stack/2.0)

Input Format:
The first line contains an integer T, the number of test cases.For each test case,
the first line contains an integer sizeOfStack denoting the stack size.
Next line contains space separated integers that will be pushed into the stack.

Output Format:
For each test case, in a new line, print the stack elements. If stack size if 1 then just print the top element.

Constraints:
1 <= T <= 100
1 <= sizeOfStack <= 100

Example:
Input:
3
5
1 2 3 4 5
7
1 2 3 4 5 6 7
4
1 2 3 4

Output:
5 4 2 1
7 6 5 3 2 1
4 3 1
 */


#include<bits/stdc++.h>
using namespace std;

stack<int> deleteMid(stack<int>s,int sizeOfStack,int current);

int main() {
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);
            
            
        }
        if(sizeOfStack==1)
        {
            cout<<myStack.top();
        }
        else
        {
        
            stack<int> modified=deleteMid(myStack,myStack.size(),0);
            
            
            while(!modified.empty())
            {
                cout<<modified.top()<<" ";
                modified.pop();
            }
        }
        cout<<endl;
        
    }   
	return 0;
}

// delete middle of a stack of size n. Curr is the current item number  
void deleteMiddle(stack<int> &s,int sizeOfStack,int current)
{
    // If all items are traversed
    if (sizeOfStack == current) // we can optimise it by if (current > sizeOfStack / 2) return coz, that part of stack need not be modified
        return;

    // remove current item
    int x = s.top();
    s.pop();

    // remove other items
    deleteMiddle(s, sizeOfStack, current+1);

    // push all items back except middle
    if (current != sizeOfStack / 2)
        s.push(x);
}

/* The idea is to use recursive calls.
First remove the items one by one
After recursive calls, push items back to stack except the middle items */
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    // pass the stack by reference to avoid copying the data in recursive calls
    deleteMiddle(s, sizeOfStack, current);
    return s;
}