/*
1. A worst case O(n2) time complexity
2. Does min no. of memory write so can be useful where write is costly.
3. In place and not stable.
4. Useful to solve questions like min no. of swaps required to sort an array.

*/

void cycleSortDistinct(int arr[] , int n)
{
    for(int cs = 0 ; cs < n - 1 ; cs++)
    {
        int item = arr[cs] ;
        int pos = cs ;

        for(int i = cs+1 ; i < n ; i++)
        {
            if(arr[i] < item)
            pos++;
        }

        swap(item , arr[pos]) ;

        while(pos != cs)
        {
            pos = cs ;
            for(int i = cs + 1 ; i < n ; i++)
            if(arr[i] < item)
                pos++ ;

            
            swap(item , arr[pos]);

        }
    }
}

