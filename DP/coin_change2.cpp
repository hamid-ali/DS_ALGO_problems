/*
https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#

Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.



*/

int minCoins(int S[], int m, int n) 
	{ 
	    int dp[m + 1][n + 1] = {-1} ;
        
        for(int i = 0 ; i < n + 1 ; i++)
        {
            dp[0][i] = INT_MAX - 1;
        }
        
        for(int i = 0 ; i < m + 1 ;i++)
        {
            dp[i][0] = 0 ;
        }
        
        
        for(int i = 1 ; i < n + 1; i++)
        {
            if(S[i] != 0 && i % S[i] == 0)
            {
                dp[1][i] =  i / S[0];
            }
            else
            {
                dp[1][i] = INT_MAX - 1 ;
            }
        }
        
        
        for(int i = 1 ; i < m + 1 ; i++)
        {
            for(int j = 1 ; j < n + 1 ; j++ )
            {
                if(S[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i][j - S[i - 1]] + 1 , dp[i - 1][j]) ;
                }
                else
                    dp[i][j] = dp[i - 1][j] ;
                
            }
        }
        
        return dp[m][n] == INT_MAX - 1  ? -1 : dp[m][n] ;
	    
	    
	    
	    
	} 