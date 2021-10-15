#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n == 1) return false;
    if( n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (n+2) )
            return false;
    }

    return true;
}

void printPrimefactors(int n)
{
    // if(n == 0 || n == 1) cout<<"no prime factors";
    // if(isPrime(n)) cout<<n<<endl;
    int i = 2;
    for(i = 2 ; i <=n ; i++)
    {
        if(isPrime(i)){
        while( n % i == 0)
        {
            cout<<i<<"  ";
            n = n/i;
        }
        }

    }
}

// void printPrimeFactors(int n)  //Naive approach
// {
// 	if(n <= 1)
// 		return;

// 	for(int i=2; i*i<=n; i++)
// 	{
// 		while(n % i == 0)
// 		{
// 			cout<<i<<" ";

// 			n = n / i;
// 		}
// 	}

// 	if(n > 1)
// 		cout<<n<<" ";

// 	cout<<endl;
// }

//Most efficient approach

// void printPrimeFactors(int n)
// {
// 	if(n <= 1)
// 		return;

// 	while(n % 2 == 0)
// 	{
// 		cout<<2<<" ";

// 		n = n / 2;
// 	}

// 	while(n % 3 == 0)
// 	{
// 		cout<<3<<" ";

// 		n = n / 3;
// 	}

// 	for(int i=5; i*i<=n; i=i+6)
// 	{
// 		while(n % i == 0)
// 		{
// 			cout<<i<<" ";

// 			n = n / i;
// 		}

// 		while(n % (i + 2) == 0)
// 		{
// 			cout<<(i + 2)<<" ";

// 			n = n / (i + 2);
// 		}
// 	}

// 	if(n > 3)
// 		cout<<n<<" ";

// 	cout<<endl;
// }

int main()
{
    int t ;
    cin>> t;

    while(t--)
    {
    int n =24 ;

        cin>> n;

    printPrimefactors(n);

    cout<<endl;

        
    }

return 0;

}