/*
https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".


*/

class Solution {
public:
    
    int lcs(string &s1, string &s2)
    {
        int x = s1.length() , y = s2.length() ;
        
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
    int longestPalindromeSubseq(string s) {
        
        string s2 = s ;
        reverse(s2.begin() , s2.end()) ;
        
        return lcs(s , s2 ) ;
        
        
    }
};