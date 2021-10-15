#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution {
public:
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        vector<int> temp ;
        int middle = sizeOfStack/2 , count = 1 ;
        while(!s.empty())
        {
            if(count < middle)
            temp.push_back(s.top());
            
            s.pop() ;
            count++ ;
            if(count > middle)
                break ;
            
        }
        int n = temp.size() ;
        for(int i = 0 ; i < n  ; i++ )
        {
            s.push(temp[i]);
        }
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends