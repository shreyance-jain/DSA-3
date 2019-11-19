#include <iostream>
using namespace std;

// linked list node
struct Node {
  int data;
  struct Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

// function to print the node
void printList(Node* n) {
    while(n != NULL) {
      cout << n->data << " ";
      n = n->next;
    }
    cout << endl;
}

// function to append a node in linked list, maintians a tail pointer
void append(Node** head_ref, Node** tail_ref, int new_data) {
  Node* new_node = new Node(new_data);
  // if head is null
  if (*head_ref == NULL) {
    *head_ref = new_node;
  } else  {
    // if head is not null
    (*tail_ref)->next = new_node;
  }
  // update the tail pointer
  *tail_ref = new_node;
}

/* This function take the node of the linked list from source
update head of source
and append the node to dest which is new linked list here */
void moveNode(Node** headRef, Node** tailRef, Node** sourceRef) {
  Node* newNode = *sourceRef;
  *sourceRef = newNode->next;

  if (*headRef == NULL) {
    *headRef = newNode;
  } else {
    (*tailRef)->next = newNode;
  }
  (*tailRef) = newNode;
}

/* 
Approach: create a new linked list
 */
Node* sortedMerge(Node* head1, Node* head2) {
  // head and tail of new linked list
  Node* head  = NULL;
  Node *tail = head;
  
  // run a indefinite loop, and will break when one of the list is exhausted
  // we also update the head pointer of the given two lists
  while(1) {
    /*we are updating the head of given linked lists*/
    // if one of the list is exhausted, point the next of new linked list to the remaining list
    if (head1 == NULL) {
      tail->next = head2;
      break;
    } else if (head2 == NULL) {
      tail->next = head1;
      break;
    }
    //  pluck the smaller node , upadte the head of linked list, and append to new linked list
    if (head1->data <= head2->data) {
      moveNode(&head, &tail, &head1);
    } else {
      moveNode(&head, &tail, &head2);
    }
  }
  // head of newly created linked list
  return head;
}

// driver code for the above program
int main() {
  int T, i, n1, n2, l, k;
  cin >> T; // no of testcases
  while (T--) {
    Node *head1 = NULL, *tail1 = NULL; // ll 1
    Node *head2 = NULL, *tail2 = NULL; // ll 2
    cin >> n1 >> n2;
    for(int i = 0; i < n1; i++) {
      cin >> l;
      append(&head1, &tail1, l);
    }
    for(int i = 0; i < n2; i++) {
      cin >> l;
      append(&head2, &tail2, l);
    }
    Node *head = sortedMerge(head1, head2);
    printList(head);
  }
  return 0;
}

// we need to sort the two linked list in-place