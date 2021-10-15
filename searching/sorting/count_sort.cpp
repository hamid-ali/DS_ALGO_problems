/*
Can not be used as a general purpose algorithm for sorting objects with multiple members,

like sorting an array of students by marks.
Important point s:- 
1. Not a comparison based algorithm.
2. theta(n+k) time complexity
3. theta(n + k) au x space
4. Stable
5. Used as subroutine in Radix sort
6. Exercise :- extend the given implementation to arbitrary range of size of k



*/

void countSort(int arr , int n , int k)
{
    int count[k];

    for(int i = 0 ; i < k ; i++)
        count[i] = 0 ;
    
    for(int i = 0 ; i < n ; i++)
        count[arr[i]]++;

    for(int i = 1 ; i < k ; i++)
    {
        count[i] = count[i-1] + count[i] ;
    }

    int output[n];

    for(int i = n- 1 ; i >= 0 ; i--)
    {
        output[count[arr[i] - 1]] = arr[i] ;
        count[arr[i]]--; 
    }
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = output[i] ;
    }





}