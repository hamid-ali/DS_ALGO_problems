/*
https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.

*/

int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n + 1][m + 1] ;
        
        int res = INT_MIN ;
        
        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = 0 ;
            
        for(int i = 0 ; i < m + 1 ; i++)
            dp[0][i] = 0 ;
        
        for(int i = 1 ; i < n + 1 ; i++)
        {
            for(int j = 1 ; j < m + 1 ; j++ )
            {
                if(S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1] ;
                }
                else
                    dp[i][j] =  0 ;
                
                
                res = max(res , dp[i][j]) ;
                 
            }
            
        }
        
        return res ;
        
    }