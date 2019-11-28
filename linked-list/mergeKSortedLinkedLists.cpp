/* 
Merge K sorted linked lists

Problem Statement

Given K sorted linked lists of different sizes
The task is to merge them in such a way that after merging they will be a single sorted linked list.

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains number of linked lists N and
next line contains data of nodes of all K linked lists,
with first element as M,
the length of linked list and next M elements for the same linked list.

Output:
For each testcase, in a new line, print the merged linked list.

Constraints
1 <= T <= 50
1 <= N <= 103

Example:
Input:
2
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8

Output:
1 2 3 4 5 5 6 7 8
1 2 3 4 5 6 8

Explanation :
Testcase 1: The test case has 4 sorted linked list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node (int d) {
        data = d;
        next = NULL;
    }
};

void printList(Node *node) {
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *sortedMerge(Node *head1, Node *head2);
Node *mergeKlists(Node *arr[], int N);

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        Node *arr[N];
        for(int j = 0; j < N; j++) {
            int n;
            cin >> n;
            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;
            for(int i = 0; i < n; i++) {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Node *res = mergeKlists(arr, N);
        printList(res);
    }
    return 0;
}

/* Approach: Divide and Conquer
We know merging of linked lists can be done in O(n) and O(1) time
The idea is to pair up k lists and merge each pair in linear time using O(1) space
After first cycle, k/2 lists are left each of size 2*N.
After second cycle, K/4 lists are left each of size 4*N
We repeat the process until we have only one list left
 */
Node *mergeKlists(Node *arr[], int N) {
    int last = N-1;
    // repeat until only one list is left
    while(last != 0) {
        int i = 0, j = last;
        // (i, j) forms a pair
        while(i < j) {
            // merge list i with list j and store merged list in i
            arr[i] = sortedMerge(arr[i], arr[j]);
            // consider next pair
            i++; j--;
            // if all pairs are merged, update last
            if (i >= j) {
                last = j;
            }
        }
    }
    return arr[0];
}

/* Take two lists sorted in increasing order, and merge their nodes
together to make one big sorted list. Below function takes O(log n)
extra space for recursive calls but it can be easily modifed to
work with same time and O(1) extra space */
Node *sortedMerge(Node *head1, Node *head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    } else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

// Time Complexity: This algo works in O(nk logk)
// as outer while loop in function mergeKlists() runs logk times
//  and every time we are processing nk elements

// Company Tags: Amazon, VMWare