/* Given an arry of n integers which conrains elements in the range 1 to n+1 .
Evry no. appears exactly once .
Hence find the missing no.

Approcah is :-
(arr[0] ^ arr[1] .. arr[n-1]) ^ (1 ^ 2 ^ 3 ^ 4 ... n, n+1)

will give the missing no. as execpt that no. each one will apprear twice and hence it  XORs to 0;

*/

/*
Finding two odd ocuuring elements 
*/
void oddAppearing(int arr[] , int n)
{
    int XOR = 0 , res1 = 0 , res2 = 0 ;

    for(int i = 0 ; i < n ; i++) 
    {
        XOR = XOR ^ arr[i] ;
    }

    int set_bit_n = XOR ^ (XOR - 1) ;

    for(int i = 0 ; i < n ;i++)
    {
        if(arr[i] & set_bit_n == 0)
            res1 = res1 ^ arr[i];

        else
            res2 = res2 ^ arr[i] ;
    }

    cout<<res1<<"   "<<res2;

}





#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[] , int n)
{   
    int res = 0;
    for(int i = 0 ; i < n; i++)
    {
        res = res ^ arr[i] ;
    }

    for(int i = 1 ; i <= n+ 1; i++)
    {
        res = res ^ i ;
    }

    return res;

}

int main()
{
    int t ;

    cin>>t ;

    while(t--)
    {
        int n ;
        cin>>n;
        int arr[n] ;
        for(int i = 0  ; i < n ; i++ )
        {
            cin>>arr[i];
        }

        cout<<missingNumber(arr , n)<<"    ";

    }



}
