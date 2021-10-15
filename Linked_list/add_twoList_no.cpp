// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

Node *revList(Node *curr , Node *prev)
{
    if(curr == nullptr) return prev;
    Node *next = curr->next ;
    curr->next = prev ;
    prev = curr ;
    curr = next;
    return revList(curr , prev) ;
    
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node *first_rev , *second_rev , *res2  , *prev = nullptr ;
    Node *temp = new Node(-1) ;
    res2 = temp ;
    
    first_rev = revList(first , prev);
    
    second_rev = revList(second , prev);
 
    int sum = 0 , carry = 0 ; 
    
    
    while(first_rev != nullptr && second_rev != nullptr)
    {   
        sum = (first_rev->data + second_rev->data + carry) % 10 ;
        carry = (first_rev->data + second_rev->data + carry) / 10 ;
        temp->data = sum ;
        // temp = new Node(sum);
        temp->next = new Node(-1) ;
        temp = temp->next ;
        if(first_rev != nullptr)
        first_rev = first_rev->next;

        if(second_rev != nullptr)
        second_rev = second_rev->next;
        
    }
    
    // sum = (first_rev->data + second_rev->data + carry) % 10 ;
    // carry = (first_rev->data + second_rev->data + carry) / 10 ;
    // temp->data = sum ;
    // temp->next = new Node(-1);

    // temp = new Node(sum);
    //     temp = temp->next ;

    // if(first_rev->next == nullptr)
    //     second_rev = second_rev->next;
    // else if(second_rev->next == nullptr)
    //     first_rev = first_rev->next ;

    while(first_rev != nullptr)
    {
        sum = (first_rev->data + carry) % 10 ;
        carry = (first_rev->data + carry) / 10 ;
        temp->data = sum ;
        temp->next = new Node(-1);
        temp = temp->next ;

        // temp = new Node(sum);
        // temp = temp->next ;
        if(first_rev != nullptr)
        first_rev = first_rev->next;
    }

    
    while(second_rev != nullptr)
    {
        sum = (second_rev->data + carry) % 10 ;
        carry = (second_rev->data + carry) / 10 ;
        temp->data = sum ;
        temp->next = new Node(-1);
        temp = temp->next ;

        // temp = new Node(sum);
        // temp = temp->next ;
        if(second_rev != nullptr)
        second_rev = second_rev->next;
    }


    if(carry > 0)
    {
        temp->data = carry;
        // temp = new Node(sum);
        // temp = temp->next ;

    }    
    prev = nullptr;  
    Node *head = revList(res2 , prev);
    if(head->data == -1){
        res2 = head;
        head = head->next ;
        delete res2;
    }
    return head;
    
}
