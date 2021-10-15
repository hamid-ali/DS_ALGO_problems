#include <bits/stdc++.h>
using namespace std;

//Modified version of square root of n approach so it will be almost 3 times faster as 
//compared to plain sqare root of(n) approach

bool isPrime(int n)
{
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (n+2) )
            return false;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        cout << isPrime(n) << endl;
    }
    return 0;
}