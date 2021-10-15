// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* sortedMerge(Node* h1, Node* h2)  
{  
   
   if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (h1->data < h2->data) { 
        h1->next = sortedMerge(h1->next, h2); 
        return h1; 
    } 
    else { 
        h2->next = sortedMerge(h1, h2->next); 
        return h2; 
    } 
   
   
}



Node* mergeSort(Node* head)
{
    if(head->next == nullptr) return head;
     Node *slow = head , *fast = head ;
     while(fast->next != nullptr && fast->next->next != nullptr)
     {
         slow = slow->next ;
         fast = fast->next->next ;
     }
     fast = slow->next ;
     slow->next = nullptr;
    Node *head1 = mergeSort(head) ;
    Node *head2 = mergeSort(fast) ;
    
    return sortedMerge(head1 , head2) ;
        
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends