// its efficient method O(n) time it will take and O(1) aux space

void sort(int arr[] , int n)
{
    int i = -1 , j = n ;
    while(true)
    {
        do i++;
        while(arr[i] < 0)

        do j++;
        while(arr[j] >= 0)

        if(i >= j) return ;

        swap(arr[i] , arr[j]);


    }


}