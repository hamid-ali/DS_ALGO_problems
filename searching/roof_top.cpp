/*
You are given heights of consecutive buildings. You can move from the roof of a building to the roof of next adjacent building. You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.

Example 1:

Input:
N = 5
A[] = {1,2,2,3,2}
Output: 1
Explanation: 1, 2 or 2, 3 are the only consecutive 
buildings with increasing heights.
Example 2:

Input:
N = 4
A[] = {1,2,3,4}
Output: 3
Explanation: 1 to 2 to 3 to 4 is the jump of
length 3 to have maximum number of 
buildings with increasing heights.
Your Task:
The task is to complete the function maxStep() which takes an array A[] (denoting the heights of buildings) and its size N as inputs and returns the maximum number of steps to gain increase in altitude.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1). 

Constraints:
1 <= N <= 104
1 <= Ai <= 104

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



int maxStep(int arr[], int N){
    int max_so_far = INT_MIN , max_end_here = 0;
    if(N==0 || N==1) return 0;
    for(int i = 1 ; i < N ; i++ )
    {
        if(arr[i-1] < arr[i])
            max_end_here ++;
        else
            max_end_here = 0 ;
            
        max_so_far = max(max_so_far , max_end_here);
    }
    
    return (max_so_far > 0 ? max_so_far : 0);
   
}

// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    cout << maxStep(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends