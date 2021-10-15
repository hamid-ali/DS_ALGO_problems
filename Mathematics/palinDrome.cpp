#include<bits/stdc++.h>
using namespace std;

bool isPalidndrome(int n)
{
    int rev = 0;
    int org_number = n ;
    while(n)
    {
        rev = rev*10 + n % 10 ;
        n /= 10;
    }

    return (rev == org_number) ;

}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        cout<< isPalidndrome(n) <<endl;

    }

    return 0;





}