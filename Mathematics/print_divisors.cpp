#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n)
{
    for(int i = 1 ; i*i <= n ; i++ )
    {
        if(n % i == 0)
        {
            cout<<i<<"  ";

            if(n/i != i)
                cout<<n/i<<"    ";


        }
    }
}

void printDivisors2(int n)  // 2 times  sqrt(n) but print divisors in sorted order
{
    int i;
    for(i = 1 ; i*i <= n ; i++)
    {
        if(n % i == 0)
            cout<<i<<"  ";
    }

    for( ; i <= n ; i++)
    {
        if(n % i == 0)
            cout<<i<<"  ";
    }
}

int main()
{
    int t ;
    cin>>t ;

    while(t--)
    {
        int n ;
        cin>> n;

        printDivisors(n);

        cout<<endl;

        printDivisors2(n)  ;

        cout<<endl;

    }

return 0;
}