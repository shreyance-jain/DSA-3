/* 
Remove duplicates from an unsorted linked list
        
Problem Statement
Given an unsorted linked list of N nodes.
The task is to remove duplicate elements from this unsorted Linked List.
If all the nodes in the linked list are equal, then remove n-1 nodes.

Input:
First line of input contains number of testcases T.
For each testcases, first line of input contains number of nodes in the linked list,
and next line contains node data for N nodes.

Output:
For each testcase, print the linked list with no repeating elements.

Constraints:
1 <= T <= 100
1 <= size of linked lists <= 50

Example:
Input:
2
4
5 2 2 4
5
2 2 2 2 2

Output:
5 2 4
2

Explanation:
Testcase 1: Given linked list elements are 5->2->2->4, in which 2 is repeated only. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4.
 */

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root) {
  Node *curr = root;
  while(curr != NULL) {
    cout << curr->data << " ";
    curr = curr->next;
  }
}

Node *removeDuplicates(Node *root);

int main() {
  int T;
  cin >> T;
  while (T--) {
    int K, data;
    cin >> K;
    struct Node *head = NULL; // head of linked list
    struct Node *tail = head; // tail of linked list
    for(int i = 0; i < K; i++) {
      cin >> data;
      // if linked list is empty set head and tail to new node
      if (head == NULL)
        head = tail = new Node(data);
      else {
        // else add to tail of linked list
        tail->next = new Node(data);
        // update tail
        tail = tail->next;
      }
    }
    Node *result = removeDuplicates(head);
    print(result);
    cout << endl;
  }
  return 0;
}

/* 
Approach: we maintain a pointer just before the current node(i.e work on curr-> next , we have hold of curr)
if data of curr->next is present in hash we simply remove the curr node using the pointer to previous node
Again: we are working on curr->next
 */
Node *removeDuplicates(Node *root) {
  Node *curr = root;
  unordered_set <int> m;
  m.insert(curr->data);
  while(curr->next != NULL) {
    if (m.find(curr->next->data) != m.end()) {
      // duplicate found del the curr->next node
      // if curr->next is the last node
      // 5 2 3 4 2
      if (curr->next->next == NULL) {
        delete(curr->next);
        curr->next = NULL;
      } else {
        // if curr->next is not the last node
        // 5 2 3 4 2 1 8
        Node *temp = curr->next;
        curr->next = temp->next;
        delete(temp);
      }
    } else {
      // insert the value in hashset
      m.insert(curr->next->data);
      // move to next node
      curr = curr->next;
    }
  }
  return root;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// Comapany Tags: Amazon, Intuit