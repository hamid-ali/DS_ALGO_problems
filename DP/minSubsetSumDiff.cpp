/*
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#

Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

*/

bool isSubsetSum(int arr[] , int n , int sum , vector<vector<bool>> &dp)
    {
        for(int i = 0 ; i < sum + 1 ; i++)
            dp[0][i] = false ;
            
        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = true ;
            
        for(int i = 1 ; i < n + 1 ; i++)
        {
            for(int j = 1 ; j < sum + 1 ; j++)
            {
                if(arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i -1]] || dp[i - 1][j] ;
                }
                else
                    dp[i][j] = dp[i -1][j] ;
            }
        }
        
    }
  
	int minDifference(int arr[], int n)  { 
    
    int sum = 0 ;
    
    for(int i = 0 ; i < n ; i++)
        sum += arr[i] ;
    
    vector<vector<bool>> dp(n + 1 , vector<bool>(sum + 1 , false)) ;
    
    isSubsetSum(arr , n , sum , dp) ;
    
    int res = INT_MAX ;
    
    for(int i = 0 ; i < sum/2 + 1; i++)
    {
        if(dp[n][i])
        res = min(res , sum - 2*i) ; 
    }
	
	
	  return res ;  
	    
	}
