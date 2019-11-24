/* 
Problem Statement:
Given two numbers represented by two linked lists,
write a function that returns the sum list.
The sum list is linked list representation of the addition of two input numbers.
It is not allowed to modify the lists.
Also, not allowed to use explicit extra space (Hint: Use Recursion).

Example
Input:
  First List: 5->6->3  // represents number 563
  Second List: 8->4->2 //  represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405

 */

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        cout << Node->data << " ";
        Node = Node->next;
    }
    cout << endl;
}

void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* tail1 = NULL;
        struct Node* second = NULL;
        struct Node* tail2 = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            append(&first, &tail1, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            append(&second, &tail2, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}

/* Function just to swap pointers */
void swapPointer(Node **a, Node **b) {
    Node *t = *a;
    *a = *b;
    *b = t;
}

/* Fucntion to get the size of linked list */
int getSize(Node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* Add two linked lists of same size represented by head1 and head2 and returns head of resultant linked list
Carry is propagated while returning from the recursion */
Node *addSameSize(Node *head1, Node *head2, int *carry) {
    // we need to make this function recursive as we need to start from the last node
    // and from there we need to add corresponding nodes in reverse order

    // Imp: Note: Throughout the code we maintain pointer to carry to update and access its value throughout

    // base case for recursion
    // since both of them are of same length and we advance both of them equally
    // we can keep check on only one head pointer
    if (head1 == NULL)
        return NULL;
    // define variable to hold sum of corresponding nodes
    int sum;

    // dummy node to begin with, so we dont access NULL->nextm its data will be overridden
    Node *result = new Node(1);

    // recursively (head recursion) add remaining nodes and get the carry
    result->next = addSameSize(head1->next, head2->next, carry);

    // add digits of current node and propagate carry
    sum = head1->data + head2->data + *carry;
    // get carry
    *carry = sum / 10;
    // reduce sum to one digit
    sum = sum % 10;

    // assign sum to current node of resultant list
    result->data = sum;
    return result;
}

/* This function is called after the smaller list is added to the bigger list's sublist of same size
Once the right sublist is added, the carry must be added to left side of larger sublist to get the final result */
void addCarryToRemaining(Node *first, Node *curr, int *carry, Node **result) {
    int sum;
    // if diff number of nodes are not traversed, add carry
    if(first != curr) {
        addCarryToRemaining(first->next, curr, carry, result);

        sum = first->data + *carry;
        *carry = sum / 10;
        sum = sum % 10;

        // add this node to the front of result
        push(result, sum);
    }
}

/* The main function that adds two linked lists represented by first and second.
The sum of two lists is stored in a list referred by result  */
Node* addTwoLists(Node* first, Node* second) {
    // if first list is empty
    if (first == NULL) return second;
    // if second list is empty
    else if (second == NULL) return first;

    // initialise head of result node
    Node *result;

    // get sizes
    int size1 = getSize(first);
    int size2 = getSize(second);

    // global carry for all functions
    int carry = 0;

    // add same size lists
    if (size1 == size2) {
        result = addSameSize(first, second, &carry);
    } else {
        // calculate diff
        int diff = abs(size1 - size2);
        
        // first list should always be greater than second list
        // if not, swap pointers
        if (size1 < size2)
            swapPointer(&first, &second);

        Node *curr;
        // move diff no of nodes in first list
        for(curr = first; diff--; curr = curr->next);
        
        // get addition of same size lists
        result = addSameSize(curr, second, &carry);

        // get addition of remaining first list and carry
        addCarryToRemaining(first, curr, &carry, &result);
    }

    // if some carry is still left, add a new node to the front of the list
    if (carry) 
        push(&result, carry);
    return result;
}

// Company tags: Accolite, Amazon, Flipkart, MakeMyTrip, Microsoft, Morgan Stanley, Qualcomm, Snapdeal