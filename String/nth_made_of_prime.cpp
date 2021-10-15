// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int primeDigits(int );

int main()
{
    int t;
    cin>>t;
    // All the above tasks are preprocessing, now you can run testcases
    // and then print the values accordingly
    while(t--)
    {
        int n;
        cin>>n;
        cout << primeDigits(n) << "\n";   
    }
}
// } Driver Code Ends


//User function template for C++

// n : given integer value

int primeDigits(int n) 
{
    string number;
    int rem = 0 ;
    while(n)
    {
        rem = n % 4 ;
        switch(rem){
        case 0: number.push_back('7');
                break ;
        case 1: number.push_back('2') ;
                break ;
        case 2: number.push_back('3') ;
                break ;
        case 3: number.push_back('5') ;
                break ;
        }
        
        if(n % 4 == 0) n--;
        n = n / 4 ;
    }
    
    reverse(number.begin() , number.end());
    return stoi(number);
    
    
}