#include <bits/stdc++.h>

using namespace std;

// structure of linked list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to print linked list
void printList(Node * head) {
    Node *node = head;
    while(node != NULL) {
        cout << node->data << ' ';
        node = node->next;
    }
    cout << endl;
}

Node *insertAtBegining(Node *head, int newData);
Node *insertAtEnd(Node *head, int newData);

// driver code
int main() {
    int test;
    cin >> test;
    while(test--) {
        int n, ch, tmp;
        Node *head = NULL;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> tmp >> ch;
            if (ch) head = insertAtEnd(head, tmp);
            else head = insertAtBegining(head, tmp);
        }
        printList(head);
    }
    return 0;
}

// function inserts the data in front of the list
Node *insertAtBegining(Node *head, int newData){
    // create a new node
    Node *new_node = new Node(newData);
    // make the head as new node next
    new_node->next = head;
    // make this new node as head
    head = new_node;
    return head;
}

// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData){
    // create a new node
    Node *new_node = new Node(newData);
    // need to handle case when linked list is empty, so we do not access null->next
    if (head == NULL)
    {
        head = new_node; // mark head as the new node and return it
        return head;
    }
    Node *last = head;
    // traverse the linked list till the last node
    while (last->next != NULL)
        last = last->next;
    // mark the next of last node as new node
    last->next = new_node;
    return head;
}

// Company Tags: Hike, TCS, Wipro