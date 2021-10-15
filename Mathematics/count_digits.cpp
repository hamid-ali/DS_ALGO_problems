#include<bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int res = 0 ;
    // while(n)
    // {
    //     res++;
    //     n /= 10;
    // }
    if(n != 0)
    res = log10(n) ;

    return res+1;
}

int main()
{
    int t;
    cin >> t ;

    while(t--)
    {
        int n ;
        cin >> n ;
        cout<< countDigits(n)<<endl;

    }

    return 0;

}