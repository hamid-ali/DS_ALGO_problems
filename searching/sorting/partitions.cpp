//Naive approach of partition
// Time complexity :- O(n) and aux space :- O(n)
void patition(int arr[] , int l , int l , int h , int p)
{
    int temp[h - l + 1] , index = 0 ;

    for(int i = l ; i <= h ; i++)
    {
        if(arr[i] <= arr[p])
            { temp[index] = arr[i] ; index++ ; }
        
    }
    for(int i = l ; i <= h ; i++)
    {
        if(arr[i] > arr[p])
            { temp[index] = arr[i] ; index++ ; }
    }

    for(int i = l ; i < h ; i++ )
    {
        arr[i] = temp[l-i] ;
    }
    
}

// Lumuto partition 
//Time complexity O(n) and O(1) aux space
// Lumito partion cab extended to work for any other pivot location
// by simply swapping it with last element initially
void swap(int a , int b)
{
    int temp = a;
    a = b ;
    b = temp;
}

int lPartition(int arr[] , int l , int h)
{
    int pivot = h;       //pivot is always the last element in Lomuto patition
    int i = l - 1;

    for(int j = l ; j < h ; j++)
    {
        if(arr[j] <= arr[pivot] )
        {
            swap(arr[++i] , arr[j]);

        }
    }

    swap(arr[++i] , arr[pivot]);

    return i;
}

/* Hoarse partition works better than Lumuto on an average
    Both Lomuto and Hoarse are not stable but the Naive partition is stable

    Hoarse's time complexity is also O(n) and aux space O(1)
*/

int hoarsePartition(int arr[] , int l , int h )
{
    int pivot = arr[l];
    int i = l - 1 , j = h - 1;

    while(true)
    {
        do { i++ ;}

        while(arr[i] < pivot)

        do { j-- ;}
        while(arr[j] > pivot)

        if(i >= j ) return j+1;

        swap(arr[i] , arr[j]) ;

    }
}