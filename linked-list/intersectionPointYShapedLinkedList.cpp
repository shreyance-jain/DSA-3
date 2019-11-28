/* 
Intersection Point in Y Shapped Linked Lists

Problem Statement

There are two singly linked lists of size N and M in a system.
But, due to some programming error the end node of one of the linked list got linked
into one of the node of second list, forming a inverted Y shaped list.
Write a program to get the point where two linked lists intersect each other.

Note: Expected time complexity is O(m + n) where m and n are lengths of two linked lists.

Input:
First line of input is the number of test cases T.
Every test case has four lines.
First line of every test case contains three numbers,
x (number of nodes before merge point in 1st list),
y (number of nodes before merge point in 11nd list) and
z (number of nodes after merge point).
Next three lines contain x, y and z values.

Output:
Print the data of the node in the linked list where two linked lists intersects.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= value <= 1000

Example:
Input:
2
2 3 2
10 20
30 40 50
5 10
2 3 2
10 20
30 40 50
10 20

Output:
5
10

Explanation:
Testcase 1: The point of intersection of two linked list is 5, means both of them get linked (intersects) with each other at node whose value is 5.
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

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *temp = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = temp;
    } else {
        (*tail_ref)->next = temp;
    }
    *tail_ref = temp;
}

int intersectPoint(Node* head1, Node* head2);

int main() {
    int T, i, n1, n2, n3, l, k;
    cin >> T;
    while(T--) {
        cin >> n1 >> n2 >> n3;
        struct Node *head1 = NULL, *tail1 = NULL;
        for(int i = 0; i < n1; i++) {
            cin >> l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL, *tail2 = NULL;
        for(int i = 0; i < n2; i++) {
            cin >> l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL, *tail3 = NULL;
        for(int i = 0; i < n3; i++) {
            cin >> l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
            tail1->next = head3;
        if (tail2 != NULL)
            tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int count(Node *head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

void swap(Node **head1, Node **head2) {
    Node *temp = *head1;
    *head1 = *head2;
    *head2 = temp;
}


/* Approach: Using difference of nodes count
1. get count of first list, be c1
2. ge count of second list be c2
3. let head1 be the list with more no nodes, so if req, swap pointers head1 and head2
4. cal diff = abs(c1-c2)
4. Now travrese the bigger list head1 in our case head1 by d nodes so that from here
   both the nodes have equal number of nodes
5. Then we traverse both the lists in parallel till we come across a common node*/
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int size1 = count(head1);
    int size2 = count(head2);
    
    int diff = abs(size1 - size2);
    
    // head1 should be always the one with more no of nodes
    if(size1 < size2) {
        swap(&head1, &head2);
    }
    
    // move head1 by diff
    Node *curr;
    for(curr = head1; diff--; curr = curr->next);
    
    // now curr and head2 are of same lengths
    // now we traverse both of them in parallel till they exhuast or have a common node
    while(curr && head2) {
        if (curr == head2) {
            return curr->data;
        }
        curr = curr->next;
        head2 = head2->next;
    }
    return -1;
}

// Time Complexity: O(m + n) where m and n are lengths of linked lists

// Company Tags: Accolite, Adobe, Amazon, D-E-Shaw, FactSet, Flipkart, Goldman Sachs
// MakeMyTrip, MAQ Software, Microsoft, Qualcomm, Snapdeal, Visa, VMWare