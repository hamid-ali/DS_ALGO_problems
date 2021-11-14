/*https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".



*/

bool isPalindrome(string &str, int i , int j)
    {
        if(i == j)
            return true ;
        
        if(i > j)
            return false ;
        
        while(i < j)
        {
            if(str[i] != str[j])
                return false ;
            i++; j--;
        }
        
        return true ;
    }

    int helper(int i , int j , string &str , vector<vector<int>> &t)
    {
        if(i > j)
        {
            return 0 ;
        }
        if(isPalindrome(str , i , j))
            return t[i][j] = 0 ;
            
        if(t[i][j] != -1)
        {
            return t[i][j] ;
        }
        
        int mn = INT_MAX ;
        for(int k = i ; k < j ; k++)
        {
            int l , r ;
            if(t[i][k] != -1)
                l = t[i][k] ;
            else l = helper(i , k , str , t) ;
            
            if(t[k + 1][j] != -1)
                r = t[k + 1][j] ;
            else
                r = helper(k + 1 , j , str , t) ;
            
            mn = min(mn , l + r + 1) ;
        }
        
        return t[i][j] = mn ; 
    }
    


    int palindromicPartition(string str)
    {
        int i = 0 , N = str.length() ;
        int j = N - 1 ;
        
        vector<vector<int>>  t(N , vector<int>(N ,-1));
        
        int res = helper(i , j , str , t) ;
        
        return res ;
        
    }