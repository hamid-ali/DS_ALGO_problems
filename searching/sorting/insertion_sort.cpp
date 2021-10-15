/* About insertion sort algorithm:-
1. O(n2) worst case

2. In place and stable

3. Used in prcatice for small arrays(Used in TimSort and Introsort)

4. O(n) in best case

5. ...

*/

void iSort(int arr[] , int n )
{
    for(int i = 1 ; i < n ; i++)
    {   
        int key = arr[i] ;
        int j = i - 1 ;
        while(j >= 0 && arr[j] > key ) // here we are not changing pos if equal so stablity maintained
        {   arr[j+1] = arr[j] ;    //shifting 1pos right all greater elements to insert arr[i] at correct pos 
            j--;

        }
        arr[j + 1] = key ; //adding 1 to j as we decrementing it at last so to go to last pos need to add 1


    }



}