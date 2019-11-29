/* 
Clone a linked list with next and random pointer

Problem Statement

You are given a Singly Linked List with N nodes where each node next pointing to its next node.
You are also given M random pointers ,
where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

Input:
First line of input contains number of testcases T. For each testcase,
first line of input contains two integers N and M.
Next line of input contains values of N nodes of the linked list and
last line contains M pairs denoting arbitrary connecting  nodes,
for which each ith node is connected to any jth node. ( ith->arb = jth ).

NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

Output:
For each testcase, clone the given linked list.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

Example:
Input:
1           
4 2                                       
1 2 3 4                             
1 2 2 4

Output:
1

Explanation:
Testcase 1: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbit pointer set, rest two nodes have arbit pointer as NULL. Third line tells us the value of four nodes. The fourth line gives the information about arbitrary pointers. The first node arbit pointer is set to node 2.  The second node arbit pointer is set to node 4.
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *arb;
    Node(int x) {
        data = x;
        next = arb = NULL;
    }
};

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

Node *copyList(Node *head);
bool validation(Node *head, Node *res, Node *cloned_addr, Node *generated_addr);

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

// driver code
int main() {
    int T, i, n, l, k;
    Node *generated_addr = NULL;
    // reading input
    cin >> T;
    while(T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            Node *tempA = head;
            int count = 1;
            while(tempA != NULL) {
                if (count == a) break;
                count++;
                tempA = tempA->next;
            }
            Node *tempB = head;
            count = 1;
            while(tempB != NULL) {
                if (count == b) break;
                count++;
                tempB = tempB->next;
            }
            if (a <= n) tempA->arb = tempB;
        }
        generated_addr = head;
        Node *res = copyList(head);
        Node *cloned_addr = res;
        cout << validation(head, res, cloned_addr, generated_addr) << endl;
    }
    return 0;
}

bool validation(Node *head, Node *res, Node *cloned_addr, Node *generated_addr) {
    if (cloned_addr == generated_addr) return false;
    Node *temp1 = head;
    Node *temp2 = res;
    int len1 = 0, len2 = 0;
    while(temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }
    if (len1 != len2) return false;
    temp1 = head;
    temp2 = res;
    while(temp1 != NULL) {
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL && temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data) return false;
        } else if (temp1->arb == NULL && temp2->arb != NULL)
            return false;
          else if (temp1->arb != NULL && temp2->arb == NULL)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

/* 
The Approach here is to use hash_map
The hash would contain key as node of original linked list
and value as node of copy linked list which we need to create
 */
Node *copyList(Node *head) {
    // hash map which contains node to node mapping of original and cloned linked list
    unordered_map<Node *, Node *> hm;

    // we traverse the original linked list
    // make the node of original linked list as key
    // and for value in hashmap we create a new copy node
    Node *curr = head;
    while(curr != NULL) {
        hm[curr] = new Node(curr->data);
        curr = curr->next;
    }

    // now we traverse the original linked list again
    // we get the cloned node address of corresponding original node using hashmap
    // now we set the next and arb of this node
    // the next of original will give the node address of from copy linked list of that node and same for arb
    curr = head;
    while(curr != NULL) {
        Node *clonedCurr = hm[curr];
        clonedCurr->next = hm[curr->next];
        clonedCurr->arb = hm[curr->arb];
        curr = curr->next;
    }
    return hm[head];
}

// Time Complexity: O(n)
// Space Complexity: O(n)