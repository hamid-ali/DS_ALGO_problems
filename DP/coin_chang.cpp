/*
https://practice.geeksforgeeks.org/problems/coin-change2448/1#
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


*/

long long int count(int S[], int m, int n)
    {
        long long dp[m + 1][n + 1] ;
        
        for(int i = 0 ; i < n + 1 ; i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i = 0 ; i < m + 1 ;i++)
        {
            dp[i][0] = 1 ;
        }
        
        
        // for(int i = 1 ; i < n + 1 && m > 1; i++)
        // {
        //     if(i % S[i] == 0)
        //     {
        //         dp[1][i] =  1;
        //     }
        //     else
        //     {
        //         dp[1][i] = INT_MAX - 1 ;
        //     }
        // }
        
        
        for(int i = 1 ; i < m + 1 ; i++)
        {
            for(int j = 1 ; j < n + 1 ; j++ )
            {
                if(S[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - S[i - 1]] + dp[i - 1][j] ;
                }
                else
                    dp[i][j] = dp[i - 1][j] ;
                
            }
        }
        
        return dp[m][n] ;
    }