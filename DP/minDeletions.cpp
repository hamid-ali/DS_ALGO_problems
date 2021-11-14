/*
https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1#

Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: S = "aebcbda"
Output: 2
Explanation: Remove characters 'e' 
and 'd'.

*/

class Solution{
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
    
    
    
    int minimumNumberOfDeletions(string S) { 
        
        string s2 = S ;
        reverse(s2.begin() , s2.end()) ;
        
        int len = lcs(S ,s2) ;
        
        return (S.length() - len) ;
        
    } 
};
