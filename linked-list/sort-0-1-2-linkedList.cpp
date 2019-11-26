/* 
Given a linked list of 0s, 1s and 2s, sort it.

Problem Statement

Given a linked list of N nodes where nodes can contain values 0s, 1s and 2s only.
The task is to segregate 0s, 1s and 2s linked list such that
all zeros segregate to headside,
2s at the end of the linked list and
1s in the mid of 0s and 2s.

Input Format:
First line of input contains number of testcases T.For each testcase,
first line of input contains length of linked list and
next line contains N elements as the data in the linked list.

Output Format:
For each testcase, segregate the 0s, 1s and 2s and display the linked list.

Constraints:
1 <= T <= 100
1 <= N <= 103

User Task:
The task is to complete the function sortList() which takes head reference as the argument and returns void.

Example:
Input:
2
8
1 2 2 1 2 0 2 2
4
2 2 0 1

Output:
0 1 1 2 2 2 2 2
0 1 2 2

Explanation:
Testcase 1: All the 0s are segregated to left end of the linked list, 2s to the right end of the list and 1s in between.
 */

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;
struct Node* segregate(struct Node *head);

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    cout << endl;
}

/* Drvier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {
    int n;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }
    return 0;
}

/* An approach for the given problem can be to count no of ones, two and threes
This can be done by taking an array of size 3 where indices of the array will represent
number of ones twos and threes
Traverse the linked list and place 0s 1s and 2s
The problem with this solution is: it would not work if the values have data associated with it
For eg: these three represent different types of colors and different types of objects
associatd with the colors, and we want to sort objects (connected with linked list) based on colors

So a preferred approach would be changing links of the linked list
Approach: Iterate through the linked list. Maintain 3 pointes named zero, one and two
pointing to cuurent ending nodes of linked list containing 0, 1, and 2 respt.
For every node traversed we attach it to end of the corresponding list.
Finally we link all three linked lists
TO avoid many null checks we use 3 dummy pointers zeroD, oneD, twoD
which works as dummy headers of given list
 */
Node* segregate(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    // Create three dummy nodes to point to 
    // beginning of three linked lists. These 
    // dummy nodes are created to avoid many 
    // null checks. 
    Node *zeroD = new Node(0);
    Node *oneD = new Node(0);
    Node *twoD = new Node(0);
    
    // initialise cuurent pointers for three lists
    Node *zero = zeroD, *one = oneD, *two = twoD; // ending nodes of respective linked lists
    
    // traverse list
    Node *curr = head;
    
    while(curr != NULL) {
        switch (curr->data) {
            case 0:
                zero->next = curr;
                zero = zero->next;
                break;
            case 1:
                one->next = curr;
                one = one->next;
                break;
            case 2:
                two->next = curr;
                two = two->next;
                break;
        }
        curr = curr->next;
    }
    
    // link the three linked lists
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;
    
    // update head
    head = zeroD->next;
    
    // delete dummy nodes
    delete zeroD;
    delete oneD;
    delete twoD;
    
    return head;   
}

// Time Complexity: O(n), where n is the number of nodes
// Space Complexity: O(1)

// Company Tags: Amazon, Microsoft, MakeMyTrip