/*
https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

*/

int lcs(int x, int y, string s1, string s2)
    {
        int dp[x + 1][y + 1] ;
        
        memset(dp, -1 , sizeof(dp)) ;
        
        for(int i = 0 ; i < x + 1 ; i++)
        {
            dp[i][0] = 0 ;
        }
        for(int i = 0 ; i < y + 1 ; i++)
        {
            dp[0][i] = 0 ;
        }
        
        for(int i = 1 ; i < x + 1 ; i++)
        {
            for(int j = 1 ; j < y + 1 ; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1] ;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j -1]) ;
                }
            }
            
        }
        
        return dp[x][y] ;
        
        
        
    }