/*
About Quick Sort :-
 1. Its divide and conquer
 2. Its key part is partitioning (Lomuto , Hoarse , Naive)
 3. Worst  case time complexity is O(n2) ; T(n) = T(n-1) + theta(n)
 4. Despite having higher worst case time complexity its preferred over the other algorithms
 due to following reasons :- 
 a. tail recursive
 b. In place
 c. Cache friendly
 d. Average case theta(nlogn)
 e. Best case :- O(nlogn) -- T(n) = 2T(n/2) + theta(n)
 
 5. Space complexity:-
 a. Worst case:- theta(n)
 b. Best case :- theta(log n) 

 Its biased to give worst performance when array is sorted in decreasing order
 To remove it we can chooese pivot elemen in random fashion :-
 p = random(l , r)
then for Hoare's  
swap(arr[l] , arr[p])

and for Lomuto

swap(arr[r] , arr[p])

*/

// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int low, int high);
/* The main function that implements QuickSort
 arr[] --> Array to be sorted, low  --> Starting index, high  --> Ending index */
void quickSort(int arr[], int low, int high) //Quick sort using Lomuto partition
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The main function that implements QuickSort
 arr[] --> Array to be sorted,    low  --> Starting index,   high  --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/
/* This function takes last element as pivot, places  the pivot element 
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot */
int partition (int arr[], int low, int high)
{
   int i = low-1, j =low;
   int key  = arr[high] ;
   while(j < high)
   {
       if(arr[j] >=key ) j++;
       else
       {
       int temp = arr[i+1];
       arr[i+1] = arr[j] ;
       arr[j] = temp;
       i++;
       j++;
       }
       
   }
   if(i < high)
   {
   int temp = arr[i+1];
   arr[i+1] = key ;
   arr[high] = temp;
    return i+1 ;
   }
   return i;
}


//Qick SOrt using Hoare's partition
void qSort(int arr[] , int l , int h)
{
    if(l < h)
    {
        int p = patition(arr , l , h) ;

        qSort(arr, l , p);

        qSort(arr , p + 1, h);

    }
}

// Tail call elimination in Quick Sort :-

void qSort(int arr[] , int l , int r)
{
    Begin:
        if(l < r)
        {
            int p = partition(arr , l , r);
            
            qSort(arr , l ,p);

            l = p+1;

            goto Begin;

        }

}