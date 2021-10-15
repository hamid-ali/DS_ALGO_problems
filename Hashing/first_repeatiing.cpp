// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


unordered_map<int, int> um;


int firstRepeated(int *, int);

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> arr[i] ;
            
        cout << firstRepeated(arr,n) << "\n";
    }

    return 0;
}
// } Driver Code Ends


//User function template in C++


// arr : given array
// n : size of the array

int firstRepeated(int arr[], int n) 
{
    // uordered_set<int> s;
    
    unordered_map<int , int> m;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(m.count(arr[i])) m.find(arr[i])->second++ ;
        
        else
        m.insert({arr[i] , 1}) ;

    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(m.find(arr[i])->second > 1) return i+1;
        
    }
    
    
    return -1;
    
}
