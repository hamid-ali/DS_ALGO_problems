// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string str)
{
    int n = str.length() ;
    stack<char> s ;
    string res="" ;
    map<char , int> precedence = {{'^' , 3} , {'*' , 2} , {'/' , 2} , {'+' ,1 } ,{'-' , 1}} ;
    
    for(int i =  0 ; i < n ; i++)
    {
        if((str[i] >= 'A' && str[i] <='Z') ||(str[i] >= 'a' && str[i] <= 'z'))
        {
            
            res.push_back(str[i]) ;
            
        }
        
        else if(s.empty() || str[i] == '(' || (!s.empty() && s.top() == '('))
        {
            s.push(str[i]) ;
        }
        else if(str[i] == ')')
        {
            while(!s.empty() || s.top() != '(')
            {
                res.push_back(s.top) ;
                s.pop() ;
            }
            s.pop() ;
        }
        
        else if(precedence.find(str[i])->second >= precedence.find(s.top()) )
        {
            s.push(str[i]) ;
        }
        else if(precedence.find(str[i])->second < precedence.find(s.top())->second )
        {
            while(precedence.find(str[i])->second < precedence.find(s.top())->second)
            {
                res.push_back(s.top());
                s.pop() ;
                if(s.empty())
                    break ;
            }
            s.push(str[i]) ;
            
        }
        
        
    }
    
    
    return res ;
    
}


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        cout<<infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends