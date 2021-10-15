/*
Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.

Example 1:

Input:
N = 5
arr[] = {1,2,3,3,4}
Output: 3 2
Explanation: In the given array, 3 is 
occuring two times.
Example 2:

Input:
N = 5
arr[] = {2,3,4,5,5}
Output: 5 2
Explanation: In the given array, 5 is 
occuring two times.
Your Task:
Complete findRepeating function and return pair of element which is repeated and the number of times it is repeated. The printing is done by the driver code.

Constraints:
1 <= N <= 107
1 <= arr[i] <= 1015

Expected Time Complexity : O(logN)
Expected Auxilliary Space : O(1)
*/
// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findRepeating(int *, int);

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    pair<int, int> ans = findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}// } Driver Code Ends


//User function template for C++

// arr : given array
// n : size of the array
pair<int, int> findRepeating(int *arr, int n)
{
    int low = 0 , high = n - 1 , mid ;
    pair <int , int> res;
    res.second = ( n - ( arr[high]- arr[low]) );
    while(low <= high)
    {
        mid = low + (high - low)/2;
        if(arr[mid] < (arr[0] + mid) )
        {   
            if(((mid > 0 && mid < n) && arr[mid] == arr[mid-1]))
            {
                res.first = arr[mid];
                return res;
            }
             high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
    
}