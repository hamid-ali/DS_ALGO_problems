// #include <bits/stdc++.h>
// using namespace std;

//Uncomment lines 1 to 2 and lines 29 to 41 to test this code right from this file 
//tested on gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 

bool solve(int n , int arr[])
{   
    unordered_map<int , int> mp; //storing count of occurence

    for(int i = 0 ; i < n ; i++)
    {
        mp[arr[i]]++ ;
    }

    for(auto x:mp)
    {
        if(x.second & 1) //checking odd even
        {
            return false ;
        }
    }

    return true ;
}

// int main(){
//         int N;
//         cin>>N;
//         int arr[N];
//         for(int i = 0;i < N;i++)
//             cin>>arr[i];

//         if(solve(N, arr))
//             cout<<"YES\n";
//         else
//             cout<<"NO\n";
//     return 0;
// }  