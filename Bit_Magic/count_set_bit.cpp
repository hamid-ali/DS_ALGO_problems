/* Brian's Kerningham algorithm
It takes time eqal to no of set bits.


*/

#include<bits/stdc++.h>

using namespace std;

int countSetbits(int n)
{
    int res = 0;

    while(n > 0)
    {
        n = n & (n - 1) ;

        res++;

    }
return res;

}

//Look up table method for 32 bits no. it will take const amount of time as we are doing preprocessing

int table[256] ;

void initialize()
{
    table[0] = 0 ;
    for(int i = 1 ; i < 256 ; i++)
    {
        table[i] = (i & 1) + table[i/2] ;
    }
}

int countSetbits2(int n)
{
    int res = 0 ;

   
        res += table[n & 0xff] ;
        
        n = n>>8;

        res += table[n & 0xff] ;
        
        n = n>>8;

        res += table[n & 0xff] ;
        
        n = n>>8;

       res += table[n & 0xff] ;
    
    

    return res;
}



int main()
{
    initialize();
    int t ;
    cin>>t;

    while(t--)
    {
        int n ;

        cin>>n;

        cout<<countSetbits(n)<<endl;

    }


}