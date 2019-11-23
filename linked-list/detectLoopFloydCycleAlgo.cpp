/* 
Detect Loop in linked list

Problem Statement

Given a linked list of N nodes.
The task is to check if the the linked list has a loop.
Linked list can contain self loop.

Input:
First line of input contains number of testcases T.For each testcase,
first line of input contains length of linked list and
next line contains the data of linked list.

Output:
For each testcase, print "True", if linked list contains loop, else print "False".

Constraints:
1 <= T <= 50
1 <= N <= 300

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0

Output:
True
False

Explaination:
Testcase 1: In above test case N = 3. The linked list with nodes N = 3 is given.
Then value of x=2 is given which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

Testcase 2: For N = 4
x = 0 means then lastNode->next = NULL, then the Linked list does not contains any loop.
 */
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

/* Function to insert node at start of linked list */
void push(Node **head_ref, int new_data) {
    Node *new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int detectLoop(Node *head);

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, x, c;
        cin >> n;
        Node *head = NULL;
        Node *s; // will make it point to tail by storing pointer of first node which we insert as we insert at begin
        cin >> x;
        push(&head, x); // add the first node
        s = head; // s will now have tail of ll as we make ll by inserting at start/beginning
        // input remaining nodes and create ll
        for(int i = 1; i < n; i++) {
            cin >> x;
            push(&head, x);
        }
        // create a loop for testing
        cin >> c;
        if (c > 0) {
            c = c-1;
            Node *temp = head;
            while(c--) temp = temp->next;
            s->next = temp;
        }
        int g = detectLoop(head);
        if (g) cout << "True";
        else cout << "False";
        cout << endl;
    }
    return 0;
}

/* Implemetation of floyd's cycle detection algo
details : DSA Notes(23-11-19)
 */
int detectLoop(Node *head) {
    // take a slow and fast ptr and initialise to head
    Node *slow_p = head, *fast_p = head;
    // fast_p->next != NULL is required so we don't access NULL->next as we increment fast by 2
    while(fast_p != NULL && fast_p->next != NULL) {
        // first increment the pointers otherwise condition will always become true
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        // after incrementing the pointers
        // check if they are equal, if yes return true
        /* fast pointer will enter the loop before slow ptr
        when slow ptr enters the loop i.e. is at loop start
        at this point fast_p will inside the loop and let us say the distance
        between fast and slow when slow enters the loop is k
        Now, k will increment by 1 because fast_p moves 2 and slow_moves 1
        now k is incrementing by 1, if there is a loop they will meet when k becomes equal to lenght of loop */
        if (slow_p == fast_p)
            return 1;
    }
    // if here return false
    return 0;
}

// Time Complexity: O(n)
// Aux Space: O(1)
// Company tags: Accolite, Amazon, D-E-Shaw, Hike, Lybrate, Mahindra Comviva, MakeMyTrip, MAQ Software, OYO Rooms,
// Paytm, Qualcomm, Samsung, SAP Labs, Sanpdeal, Veritas, VMWare, Walmart