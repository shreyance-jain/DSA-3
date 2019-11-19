#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(struct Node* a, struct Node* b);

// function to insert node in the last of linked list, maintains a tail pointer
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;
    cin>>T;
    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;
        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
 
// in-place recursive algorithm
Node* sortedMerge(Node* head1, Node* head2)
{
    if (!head1) return head2;
    if (!head2) return head1;
    // pick the node head1 and recursively call on remaining linked lists
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    // pick the node head2 and recursively call on remaining linked list
    else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

/* 
Company Tags: Accolite, Amazon, Belzabar, Brocade, FaceSet, Flipkart, MakeMyTrip, Microsoft, OATS Systems,
            Orcale, Samsung, Synopsys, Zoho
 */