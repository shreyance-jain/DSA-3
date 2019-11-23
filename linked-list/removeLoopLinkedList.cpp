/* 
Remove loop in Linked List

Problem Statement

You are given a linked list of N nodes.
The task is to remove the loop from the linked list, if present.

Input:
First line of input contains number of testcases T. T testcases follow.
For each testcase, first line of input contains length N of the linked list and
next line contains N data of the linked list.
The third line contains the position of the node(from head) to which the last node will get connected.
If it is 0 then there is no loop.

Output:
For each testcase, in a new line, 1 will be printed if loop is removed(correct answer)
else 0 will be printed(for wrong answer).

Constraints:
1 <= T <= 50
1 <= N <= 300

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0

Output:
1
1

Explanation:
Testcase 1: In the first test case N = 3.
The linked list with nodes N = 3 is given. Here, x = 2 which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

Testcase 2: N = 4 and x = 0, which means lastNode->next = NULL, thus the Linked list does not contains any loop.
 */

#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
 Node* insert(Node* head, int data)
{
    if (head == NULL)
        head = new Node(data);
    else
        head->next = insert(head->next, data);
    return head;
}
 void makeLoop(Node* head, int x)
{
    if (x == 0)
        return;
    Node* curr = head;
    Node* last = head;
    int counter = 0;
    while (counter < x)
    {
        curr = curr->next;
        counter++;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = curr;
}
 int detectloop(Node* head)
{
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise && hare != NULL && tortoise != NULL)
    {
        hare = hare->next;
        tortoise = tortoise->next;
        if (hare != NULL && hare->next != NULL)
            hare = hare->next;
        if (hare == tortoise)
            return 1;
    }
    if (hare == tortoise)
        return 1;
    return 0;
}
 int length(Node* head, bool hasloop)
{
    int len = 0;
    if (hasloop == false)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    else
    {
        Node* hare = head->next;
        Node* tortoise = head;
        while (hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
            hare = hare->next;
            if (hare == tortoise)
                break;
        }
       
        int looplen = 0;
        while (hare->next!=tortoise)
        {
            hare = hare->next;
            looplen++;
        }
        
        looplen++;
        Node* begin = head;
        int startlen = 0;
        tortoise = tortoise->next;
        while (begin != tortoise)
        {
            
            begin = begin->next;
            tortoise = tortoise->next;
            startlen++;
        }
        
        return looplen + startlen;
        
    }
}
void removeTheLoop(Node *head);

int main() {
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *head=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
            head=insert(head,arr[i]);
            
        }
        int x;
        cin>>x;
        makeLoop(head,x);
        int lengthll=0;
        if(detectloop(head)==1)
        lengthll=length(head,true);
        else
        lengthll=length(head,false);
        
        removeTheLoop(head);
        
        if (detectloop(head) == 0 && lengthll == length(head, false))
        {
            cout<<1<<endl;
        }
        else
        cout<<0<<endl;
    }
	return 0;
}

/* Detail explanation DSA Notes 23-11-19 */
void removeTheLoop(Node *head)
{
    // detect loop using floyd's loop detection
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        // advance pointers first otherwise detecting condition will always become true
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast) return;
    // now claim is move slow to head and move slow and fast at same speed
    // they meet at starting/first node of the loop
    slow = head;
    while(slow->next != fast->next) {// to keep hold of fast since we will change its next we compare next pointers
        slow = slow->next;
        fast = fast->next;
    }
    // change the next of fast to NULL
    fast->next = NULL;
    return;
}

// Company Tags: Adobe, Amazon, GoldmanSachs, Kuliza, MakeMyTrip, Microsoft, Morgan Stanley,
// Netskope, Oracle, Qualcomm, Snapdeal, VMWare, Walmart