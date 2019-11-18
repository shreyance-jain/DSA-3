#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root);
Node* removeDuplicates(Node *root);

int main() {
  int T;
  cin >> T;
  while(T--) {
    int K;
    cin >> K;
    Node *head = NULL; // head of linked list
    Node *tail = head; // tail of linked list
    for(int i = 0; i < K; i++) {
      int data;
      cin >> data;
      // if linked list is empty set head and tail to new node
      if (head == NULL) {
        head = tail = new Node(data);
      } else {
        // add to tail of linked list
        tail->next = new Node(data);
        tail = tail->next; // update tail
      }
    }
    Node *result = removeDuplicates(head);
    print(result);
    cout << endl;
  }
}

void print(Node *root) {
  Node *curr = root;
  while(curr != NULL) {
    cout << curr->data << " ";
    curr = curr->next;
  }
}

/* 
We use the logic of deleting a node with only a pointer given to it
In this we use to copy the value of the next node in the node to be
deleted and delete the next node whose data is now stored

Similarly, when we see duplicates, here we don't need to copy the value
in the previous node as both the nodes has same value, we get hold of next node
and delete it and link the next of previous node to next of next node
eg i/p: 2 2 4 5
   o/p: 2 4 5
i/p: 2 2 2 2
o/p: 2
 */
Node* removeDuplicates(Node *root) {
  Node *curr = root;
  // traverse the linked list
  while(curr->next != NULL) {
    // if data is same
    if (curr->data == curr->next->data) {
      // hold next node in a temp pointer
      Node *temp = curr->next;
      // chnage next of current to next of next
      curr->next = temp->next;
      // free the temp pointer
      delete(temp);
    } else {
      // else move to next, we don't increment every time as there might be more than 2 duplicates continously
      curr = curr->next;
    }
  }
  return root;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

// Company Tags: Adobe, Myntra, Oracle, OYORooms, Visa