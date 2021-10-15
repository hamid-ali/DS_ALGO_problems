// { Driver Code Starts
// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in
// alphabatical order
char* countSort(char arr[]);

// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        printf("%s\n", countSort(arr));
    }
    return 0;
}

// } Driver Code Ends


// The main function that sort the given string arr[] in
// alphabatical order
// return the sorted char array
char* countSort(char arr[])
{
    int count[26]={0};
    int len = 0 , i = 0 ;
    // char res[len];
    while(arr[i] != '\0' )
    {
        count[arr[i] - 97]++;
        len ++;
        i++;
    }
    i = 0;
    for(int j = 0 ; j < 26 ; j++)
    {  
        while(count[j] != 0)
        {
        arr[i] = j + 97 ;
        count[j]--;
        i++;
        }
    }
    
    return arr;

}