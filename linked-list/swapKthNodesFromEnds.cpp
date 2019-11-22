/* 
Swap Kth nodes from ends

Problems

Given a singly linked list of size N, and an integer K.
You need to swap the Kth node from beginning and Kth node from end in linked list.
Note: You need to swap the nodes through the links and not changing the content of the nodes.

Input: 
First line of input contains the number of testcases T.
The first line of every testacase contains N, number of nodes in linked list,
and K the nodes to be swapped and
the second line of contains the elements of the linked list.

Output:  
For each testcase, if the nodes are swapped correctly, the output will be 1, else 0.

User Task: 
The task is to complete the function swapkthnode(), which has arguments
head, num and K, and  it should return new head.
The validation is done internally by the driver code to ensure that the swapping is done by
changing references/pointers only. 
A correct code would always cause output as 1.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= K <= 103

Example:
Input:

3
4 1
1 2 3 4
5 3
1 2 3 4 5
3 4
1 2 3 4

Ouput:
1
1
1

Explanation:
Testcase1: Here K = 1, hence after swapping the 1st node from beginning and end the new list will be 4 2 3 1
 */

#include <bits/stdc++.h>
using namespace std;

// structure of node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to append nodes in linked list, maintains references/pointers of head nd tails poineters */
void append(Node** head_ref, Node** tail_ref, int new_data) {
    Node* newnode = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = newnode;
    } else {
        (*tail_ref)->next = newnode;
    }
    *tail_ref = newnode;
}

/* Function stores node of linked lists in arr of node struct */
void addressstore(Node **arr, Node *head) {
    Node *temp = head;
    int i = 0;
    while(temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

/* Function checks the address as well as data by comparing struct at positions before and after */
bool check(Node **before, Node **after, int num, int K) {
    if (K > num)
        return 1;
    return ((before[K-1] == after[num-K]) && before[num - K] == after[K-1]);
}

Node *swapkthnode(Node *head, int num, int K);

/* driver code */
int main() {
    int T;
    cin >> T;
    while(T--) {
        int num, K;
        cin >> num >> K;
        int temp;
        Node *head = NULL;
        Node *tail = NULL;
        for(int i = 0; i < num; i++) {
            cin >> temp;
            append(&head, &tail, temp);
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

/* There are many interesting cases in this problem:
Let X be the kth node from beginning and Y be the kth node from end
Following are the interesting cases that must be handled.
1. Y is next to X
eg: 1->2->3->4  if, k = 2
       X  Y 
2. X is next to Y
eg: 1->2->3->4 if, k = 3
       Y  X 
3. X and Y are same
eg: 1->2->3->4->5 if, k = 3
         X,Y
4. X and Y doesn't exist (K is more than number of nodes in linked list)
*/
Node *swapkthnode(Node* head, int num, int K)
{
    // num->no of nodes in linked list
    // if no of nodes is not given, then we need to traverse
    // the linked list and get count of no of nodes

    // check if K is valid
    if (num < K) return head;

    // x (kth node from start) and y (kth node from end) are same
    if (2*K - 1 == num) return head;
    
    // Find the kth node from beginning of linked list. We also find
    // previous of kth node because we need to update next pointer of
    // the previous
    Node *x = head;
    Node *x_prev = NULL;
    for(int i = 1; i < K; i++) {
        x_prev = x;
        x = x->next;
    }
    
    // Similarly, find the kth node from end and its previous. kth node
    // from end is (n-k+1)th node from beginning
    Node *y = head;
    Node *y_prev = NULL;
    for(int i = 1; i < num-K+1; i++) {
        y_prev = y;
        y = y->next;
    }
    
    // if x_prev exists, the new next if it will be y. Consider the case
    // when y->next is x,  in this case x_prev and y are same. So the statement
    // "x_prev->next = y" creates a self loop. This self loop will be broken
    // when we change y->next
    if (x_prev)
        x_prev->next = y;
    
    // Same thing apply to y_prev
    if (y_prev)
        y_prev->next = x;
    
    // Swap next pointers of x and y. These statements also break self
    // loop if x->next is y or y->next is x
    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    // change head pointers if k is 1 or n
    if (K==1) head = y;
    if (K==num) head = x;
    
    return head;
}

// Company tags: Amazon, Morgan Stanley