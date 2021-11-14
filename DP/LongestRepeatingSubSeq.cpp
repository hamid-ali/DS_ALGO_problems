/*
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.

Example 1:

Input:
str = "axxxy"
Output: 2


*/

int LongestRepeatingSubsequence(string str){
		    int n = str.length() ;
		    
		    string s2 = str ;
		    
		    int dp[n + 1][n + 1];
		    
		    for(int i = 0 ; i < n + 1 ; i++)
		    {
		        dp[0][i] = 0;
		        dp[i][0] = 0;
		    }
		    
		    for(int i = 1 ; i < n + 1 ; i++)
		    {
		        for(int j = 1 ; j < n + 1 ; j++)
		        {
		            if(str[i - 1] == s2[j - 1] && i != j )
		            {
		                dp[i][j] = 1 + dp[i - 1][j - 1];
		            }
		            else
		            {
		                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) ;
		            }
		        }
		        
		    }
		    
		    return dp[n][n] ;
		    
		}