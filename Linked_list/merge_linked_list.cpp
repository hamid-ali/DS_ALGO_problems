// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* head_A, Node* head_B)  
{
    Node *temp , *root ;
    if(head_A->data <= head_B->data)
        {
            root = head_A ;
            head_A = head_A->next ;
        }
    else    
        {
            root = head_B ;
            head_B = head_B->next ;
        }
    
    temp = root ;
    
    while(head_A->next != nullptr && head_B->next != nullptr)
    {
        if(head_A->data <= head_B->data)
            {
                root->next = head_A ;
                head_A = head_A->next ;
                root = root->next ;
            }
        else
        {
            root->next = head_B ;
            head_B = head_B->next ;
            root = root->next ;
            
        }
        
    }
    
    if(head_A->next == nullptr)
    {
        // root->next = head_A ;
        head_A->next = head_B ;
    }
    else
    {
        // root->next = head_B ;
        head_B->next = head_A ;
    }
    return temp ;
    
}  