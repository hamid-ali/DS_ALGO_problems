#include<bits/stdc++.h>
using namespace std;

int countZeroes( int n)
{
    int count = 0;
    while(n != 1)
    {
        int temp = n;
        while(temp != 0 && temp % 5 == 0)
        {
            count++;
            temp /= 5;
        }
        n--;
    }

return count;


}

int main()
{
    int t ;
    cin>> t;
    while(t--)
    {
        int n;
        cin >> n;

        cout << countZeroes(n) <<endl;



    }
// return 0;

}