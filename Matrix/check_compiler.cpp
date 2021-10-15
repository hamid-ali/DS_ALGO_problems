#include<iostream>

using namespace std;

int main()
{
    int m = 3 , n = 2 ;
    int **arr;
    arr = new int *[m] ;

    for(int i = 0; i< n ; i++)
    {
        arr[i] = new int[n] ;
    }

    for(int i = 0 ; i< m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            arr[i][i] = i + j ;

        }
    }

    for(int i = 0; i< m ;i++)
    {
        for(int j = 0 ; j < n ; j++ )
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
