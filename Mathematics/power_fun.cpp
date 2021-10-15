/*
Power fun can be implemented in theta(log n) time.
Its recursive soln will require theta(log n) space as well and fuction call overhead

however its itertive will require const. amt of space and it will be faster.

*/

#include<bits/stdc++.h>

using namespace std;

int power(int base , int index)  //recursive implementation.
{
    if(index == 0)
        return 1;

    int temp =  power(base , index/2);

    if(index % 2 ==0 )
        return temp * temp;

    
    return base*temp*temp;

}

//Iterative soln in a different way O(log n) time and const space and optimized using bits operation

int power_itr(int x , int n)
{
    int res = 1 ;

    while(n > 0)
    {
        if(n & 1)
        {
            res = res * x ;
        }

        x = x * x;

        n = n>>1;
    }
return res;

}

int main()
{
    int t;
    cin>> t;

    while(t--)
    {
        int n ,p ;
        cin>> n >> p ;

        cout<< power_itr(n , p)<<endl;

    }

    return 0;


}