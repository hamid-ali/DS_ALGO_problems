//key function of Merge Sort

void merge(int arr[ ] , int l , int m , int h)// O(n) time and O(n) aux space
{
    int n1 = m - l + 1 , n2 = h - m ;

    int left[n1] , right[n2] ;

    for(int i = 0 ; i < n1 ; i++) left[i] = arr[ l + i] ;

    for(int i = 0 ; i< n2 ;i++) right[i] = arr[m + 1 + i] ;

    int i = 0 , j = 0 , k = l ;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++] ;
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while(i < n1) arr[k++] = left[i++] ;

    while(j < n2) arr[k++] = right[j++] ;

}

//Merging two sorted arrays Naive approach
// O(m+n)log(m+n) time and O(m+n) aux space

void merge(int a[] , int b[] , int m , int n)
{
    int c[m+n] ;

    for(int i = 0 ; i < m ; i++) c[i] = a[i] ;

    for(int i = 0 ; i < n ; i++) c[m + i + 1] = b[i];

    sort(c , c + m + n); //Arrays.sort

    for(int i = 0 ; i < m+n ; i++)
    {
        cout<< c[i] << " " << endl;
        
    }


//Merge two sorted array better approach with O(m+n) time and O(m+n) aux space

void merge(int a[] , int b[] , int m , int n)
{
    int i = 0 , j = 0;
    while(i < m && j < n)
    {
        if(a[i] <= b[j])
        {
            cout << a[i++];
        }
        else
        {
            cout << b[j++];
        }
    }

    while(i < m) cout<< a[i++];

    while(j < n) cout<< b[j++];
}









}



//Merge sort algorithm
// Time complexity O(nlogn) rather theta (n)*logn and aux space is O(n)

void mergeSort(int arr[], int l , int r)
{
    if(r > l) // at least two elements
    {
        int mid = l + (r - l )/2 ;

        mergeSort(arr , l , mid);

        mergeSort(arr , mid + 1 , r) ;

        merge(arr , l , mid , r);

    }

}