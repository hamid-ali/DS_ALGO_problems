/* printing SCS
https://leetcode.com/problems/shortest-common-supersequence/


092. Shortest Common Supersequence
Hard

1601

34

Add to List

Share
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1 = str1.length() , n2 = str2.length() ;
        
        int dp[n1 + 1][n2 + 1] ;
        
        for(int i = 0 ; i < n1 + 1 ; i++)
            dp[i][0] = 0 ;
        
        for(int j = 0 ; j < n2 + 1 ; j++)
            dp[0][j] = 0 ;
        
        for(int i = 1; i < n1 + 1 ; i++)
        {
            for(int j = 1 ; j < n2 + 1 ; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1] ;
                    
                }
                else
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
            }
        }
        
        string res = "" ;
        
        int i = n1 , j = n2 ;
        
        while(i > 0 && j >0)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                res.push_back(str1[i - 1]);
                i-- ;
                j-- ;
            }
            else if(dp[i - 1][j] > dp[i][j - 1])
            {
                res.push_back(str1[i - 1]) ;
                i-- ;
                
            }
            else
            {
                res.push_back(str2[j - 1]) ;
                j--;
            }
            
        }
        
        while(i > 0)
        {
            res.push_back(str1[i - 1]) ;
            i-- ;
        }
        while(j > 0)
        {
            res.push_back(str2[j - 1]) ;
            j-- ;
            
        }
        
        reverse(res.begin() , res.end()) ;
        
        return res ;
    }
};