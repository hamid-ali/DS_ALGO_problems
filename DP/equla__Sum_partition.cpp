/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1# 
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

*/

class Solution{
public:

    bool isSubSetSum(int arr[] , int n , int sum)
    {
        bool dp[n + 1][sum + 1] = {false} ;
        
        for(int i = 0 ; i < sum + 1 ; i++)
            dp[0][i] = false ;
            
        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = true ;
        
        for(int i = 1 ; i < n + 1 ; i++)
        {
            for(int j = 1 ; j < sum + 1 ; j++)
            {
                if(arr[i - 1] <= sum)
                {
                    dp[i][j] = dp[i -1][j - arr[i - 1]] || dp[i-1][j] ;
                }
                
                else
                dp[i][j] = dp[i-1][j] ;
                
            }
        }
        
        return dp[n][sum] ;
        
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0 ;
        for(int i = 0 ; i < N ; i++)
            sum += arr[i] ;
            
        if(sum & 1)
            return 0 ;
            
        return isSubSetSum(arr , N , sum/2) == true ? 1 : 0 ;
        
        
    }
};