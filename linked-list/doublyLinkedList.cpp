#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

Node *insertAtLast(Node *head, int new_data);
void addNode(Node *head, int pos, int data);
void printList(Node *head);

// driver code
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, tmp, pos, data;
        Node *head = NULL;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            head = insertAtLast(head, tmp);
        }
        cin >> pos >> data;
        addNode(head, pos, data);
        printList(head);
    }
    return 0;
}

// function to insert at last of Doubly Linked List
Node *insertAtLast(Node *head, int new_data) {
    // case when linked list is empty
    if (head == NULL) return new Node(new_data);
    // take head in a temp pointer say last
    Node *last;
    // traverse till last node
    for(last = head; last->next != NULL; last = last->next)
        ;
    // creat a new node with given data
    Node *new_node = new Node(new_data);
    // insert the new node at last
    last->next = new_node; // point next of last to new node
    new_node->prev = last; // point prev of new node to last
    // return head
    return head;
}

// function to print Doubly Linked List
void printList(Node *head) {
    Node *temp = head;
    // the purpose of the below two loops is to test the created DLL
    if (temp != NULL) {
        while(temp->next != NULL)
            temp = temp->next;
        while(temp->prev != NULL)
            temp = temp->prev;
    }
    while(temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

// function to add a new node at given position in Doubly linked list
void addNode(Node *head, int pos, int data) {

    // create a new node
    Node *new_node = new Node(data);
    Node *curr = head;

    // traverse linked list till given positon
    while(pos--) {
        curr = curr->next;
    }
    // if curr next is null, i.e. at last node
    if (curr->next == NULL) {
        curr->next = new_node;
        new_node->prev = curr;
    } else {
        new_node->next = curr->next; // make the new node next as curr node next
        curr->next->prev = new_node; // now change the initial current node next prev to new node
        curr->next = new_node; // now change the current node next to new node
        new_node->prev = curr; // make the new node prev as current node
    }
}

// Company Tags: Visa