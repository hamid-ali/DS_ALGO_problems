// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





//User function template for C++


map<int,int> mp; // mp hold 1 to those number which consists of only 1, 2, 3 as digits only 
void findAll()
{
    // long long num = 1 ;
    
    // while(num <= 1000000)
    // {   
        
    //     long long int temp = num ; bool flag =  true;
    //     while(temp == 0 && flag)
    //     {
    //         if(temp % 10 == 1  || temp % 10 == 2 || temp % 10 ==3)
    //         {   
    //             temp /= 10;
    //             continue;
    //         }
    //         else flag = false;
            
            
    //     }
    //     if(flag) mp.insert({num , 1});
        
    //     num++ ;
    // }
    
    unordered_set<int> s;
    
    s.insert(1) ;
    s.insert(2) ;
    s.insert(3) ;
    
    for (int i = 1; i <= 1000000; ++i) {
        int n = i;
        while (n > 0) {
            if (!s.count((n % 10))) break;
            n /= 10;
        }
        if (n == 0) mp.insert({i, 1});
    }
    
    
}


// { Driver Code Starts.


int main()
{   
    findAll(); // find all such numbers whose digits are from set {1,2,3} from 1 to 1000000
    int t;
    cin>>t; 
    
    while(t--)
    {
        int n, flag=0;
        cin>>n; 
        
        int arr[n] ;
        
        for(int i=0;i<n;i++) // insert n elements
            cin >> arr[i]; 
        
        sort(arr,arr+n); // sort them
        
        for(int i = 0 ; i < n ; ++ i ) {
            if(mp[arr[i]]) { // if arr[i] is already there in the map then it satisfied else not 
                cout << arr[i] << " " ;
                flag=1;
            }
        }
        
        if(!flag)
            cout << "-1"; 
            
        cout<<endl;
    }
return 0;
}  // } Driver Code Ends