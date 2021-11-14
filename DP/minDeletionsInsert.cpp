/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1#

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3


*/

int minOperations(string s1, string s2) 
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
        
        return (x - dp[x][y] + y - dp[x][y]) ;
	    
	    
	    
	} 