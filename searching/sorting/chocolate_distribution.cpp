/* I/P:- {7, 3 , 2 ,4 , 9 ,  12 , 56}

m = 3

o/p :- 2

we have to distribute one chocolate  box to each and every of m children
such that diff b/w min and max is minimum and each one will get exactly one pocket


*/
#include <iostream>
using namespace std;


int minDifference(int arr , int n , int m)
{
    if(m > n) return -1;
    sort(arr, arr+n);
    int res = arr[m - 1] - arr[0] ;
    for(int i = 1 ; i+m-1 < n ; i++)
    {
        res = min(res , arr[i +m - 1]) ;
    }

    return res;

}