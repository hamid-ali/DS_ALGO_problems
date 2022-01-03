// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

struct Node{
      int key , value ;
      Node *prev , *next ;
      
      Node(int key ,int value)
      {
          key = key ;
          value = value ;
          next = nullptr ;
          prev = nullptr ;
      }
    }; 

class LRUCache
{
    private:
    
    public:
    
    int capacity , size ;
    Node *head , *tail; 
    unordered_map<int , Node *> mp;
    
    void *deleteNode(Node *toBedeleted)
    {
        if(head == tail)
        {
            Node *temp = toBedeleted ;
            delete(temp);
            head = nullptr ;
            tail = head ;
            
        }
        else if(toBedeleted == tail)
        {
            Node *temp = toBedeleted ;
            tail = temp->prev ;
            tail->next = nullptr ;
            delete(temp);
        }
        else{
            Node *temp = toBedeleted ;
            temp->prev->next = temp->next ;
            temp->next->prev = temp->prev ;
            
            delete(temp);
        }
    }
    
    void addToHead(Node *ptr)
    {
        if(head == nullptr)
            {
                head = ptr ;
                tail = head ;
                return ;
            }
        ptr->next = head ;
        head->prev = ptr ;
        
        if(tail == head)
            tail = ptr ;
        
        head = ptr ;
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->capacity = cap ;
        // size = 0 ;
        head = nullptr ;
        tail = nullptr ;
        
        // unordered_map<int , Node*> temp;
        // temp.insert({0 , head});
        // mp = temp;
        
        
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(size == 0)
            return -1 ;
        if(!mp.count(key))
        {
            return -1 ;
        }
        Node *temp = mp.find(key)->second;
        int ans = temp->value ;
        deleteNode(temp);
      Node *temp2 = new Node(key, ans);
        addToHead(temp2);
        return ans ;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(size == 0)
        {
            Node *temp = new Node(key , value);
            addToHead(temp);
            mp.insert({key , temp});
            size++;
            return ;
        }
        
        if(mp.count(key))
        {
            mp.find(key)->second->value = value ;
            return ;
        }
        
        if(size == capacity)
        {
            deleteNode(tail);
            Node *temp = new Node(key , value);
            addToHead(temp);
            mp.insert({key , temp});
            return ;
        }
        
        Node *temp = new Node(key , value);
        addToHead(temp);
        mp.insert({key , temp});
        size++;
           
    }
};




// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        // cout<<"queries count is "<<queries ;
        while (queries--)
        {
            string q;
            cin >> q;

            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout<<key ;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends