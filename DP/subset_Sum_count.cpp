/*
https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

*/

int perfectSum(int arr[], int n, int sum)
	{
        int dp[n + 1][sum + 1] = {-1};
        
        int M = 1000000007 ;
        
        int count = 0 ;
        
        for(int i = 0 ; i < sum + 1 ; i++)
            dp[0][i] = 0 ;
            
        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = 1 ;
            
        for(int i = 1 ; i < n + 1 ; i++)
        {
            for(int j = 1 ; j < sum + 1 ; j++)
            {
                if(arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] % M + dp[i -1][j] % M ) % M;
                    
                }
                else
                    dp[i][j] = dp[i -1][j] ;
            }
        }
        
        return dp[n][sum] ;
	}