/*
https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

*/

class Solution{
  public:
    int cutRod(int price[], int n) {
        
        int wt[n];
        for(int i = 0 ; i < n ; i++)
        {
            wt[i] = i + 1 ;
        }
        
        int dp[n + 1][n + 1] ;
        
        for(int i = 0 ; i < n + 1 ; i++)
        {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        for(int i = 1 ; i < n + 1 ; i++)
        {
            for(int j = 0 ; j < n + 1 ; j++)
            {
                if(wt[i - 1] <= j)
                {
                    dp[i][j] = max( (price[i - 1] + dp[i][j - wt[i - 1]]) , 
                                dp[i - 1][j]) ;
                }
                else
                    dp[i][j] = dp[i - 1][j] ;
                
            }
        }
        
        return dp[n][n] ;
    }
};