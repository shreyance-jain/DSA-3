/* 
Merge Sort for Linked List

Problem Statement

Given Pointer/Reference to the head of the linked list,
the task is to Sort the given linked list using Merge Sort.

Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Input:
First line of input contains number of testcases T.
For each testcase,
first line of input contains number of nodes in the linked list and
next line contains N elements of the linked list.

Output:
For each test, in a new line, print the sorted linked list.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
5
3 5 2 4 1
3
9 15 0

Ouput:
1 2 3 4 5
0 9 15

Explanation:
Testcase 1: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.
 */


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function prototypes */
Node *sortedMerge(Node *a, Node *b);
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef);
Node *mergeSort(Node *head);

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}

/* Split the nodes of the given linked list into front and back halves
and return the two lists using reference parameters
If the length is odd, the extra space should go in the front list
Uses the fast/slow pointer strategy*/
void FrontBackSplit(Node *source, Node **front_ref, Node **back_ref) {
    Node *slow = source;
    Node *fast = source->next; // !imp, will make slow point to first middle node when no of nodes are even
    
    // advance fast by 2 and slow by 1
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // split the list using the slow pointer
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}   

Node *sortedMerge(Node *head1, Node *head2) {
    // base cases
    if (!head1) return head2;
    if (!head2) return head1;
    
    // pick one node and recur
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    } else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

// Sort the list by changing pointers (not data)
Node* mergeSort(Node* head) {
    Node *a;
    Node *b;
    
    // base case: length 0 or 1
    if (head == NULL || head->next == NULL)
        return head;
    
    // spilt head into 'a' and 'b' sublists
    FrontBackSplit(head, &a, &b);
    
    // recursively sort the sublists
    a = mergeSort(a);
    b = mergeSort(b);
    
    // answer = merge the two sorted lists together
    // head node to be changed if the data at the original head is not the smallest value in linked list
    // we are not swapping data, we are changing pointers
    head = sortedMerge(a, b);
    return head;
}

/* void merge_sort(Node **head_ref) {
    Node *head = *head_ref;
    Node *a;
    Node *b;
    
    if (head == NULL || head->next == NULL)
        return;
    
    FrontBackSplit(head, &a, &b);
    
    merge_sort(&a);
    merge_sort(&b);
    
    *head_ref = mergeUtil(a, b);
} */

// Time Complexity: O(nlogn)
// Company Tags: Accolite, Adobe, Amazon, MAQ Software, Microsoft, Paytm, Veritas