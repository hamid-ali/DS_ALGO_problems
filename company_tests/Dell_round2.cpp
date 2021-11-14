struct Node{
    int data ;
    Node *next ;
}

Node *reverseList(Node *head)
{
    Node *curr , *prev , *next;

    curr = head ; prev = nullptr ; next = head ;

    if(head == nullptr)
        return head ;

    while(curr != nullptr && curr->next != nullptr)
    {
        next = curr->next ;
        
        curr->next = prev ;//

        prev = curr ;

        curr = next ;

    }
    curr->next = prev ;

    return curr ;

}