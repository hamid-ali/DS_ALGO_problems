/*
https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))

*/

  int helper(int i , int j , string &str, unordered_map<string , int> &mp , bool isTrue)
    {
        if(i > j )
            return 0 ;
        
        if( i == j)
        {
            if(isTrue)
                return str[i] == 'T';
            else
                return str[i] == 'F' ;
        }
        
        string key = to_string(i) ;
        key.push_back('_');
        
        key.append(to_string(j)) ;
        key.push_back('_');
        key.append(to_string(isTrue)) ;
        
        
        if(mp.find(key) != mp.end())
        {
            return mp[key] ;
        }
        
        int ans = 0 ;
        for(int k = i + 1 ; k <= j - 1 ; k = k + 2)
        {
            int lT = helper(i , k - 1 , str , mp , true) ;
            
            int lF = helper(i, k - 1 , str , mp , false) ;
            
            int rT = helper(k + 1 , j , str , mp , true) ;
            
            int rF = helper(k + 1 , j ,str , mp , false) ;
            
            if(isTrue)
            {
                        if(str[k] == '|')
                        {
                            ans += (lT*rF + lF*rT + lT*rT );
                        }
                        else if(str[k] == '&')
                        {
                            ans += (lT*rT );
                        }
                        else if(str[k] == '^')
                        {
                            ans += (lT*rF + lF*rT) ;
                        }
                        
            }
                        
            else
            {
                if(str[k] == '|')
                {
                    ans += (rF*lF) ;
                }
                else if(str[k] == '&')
                {
                    ans += (lT*rF + lF*rT + lF*rF ) ;
                }
                else if(str[k] == '^')
                {
                    ans += (lT*rT + lF*rF) ; 
                }
                
            }
            
        //   mp[key] = ans % 1003 ;  
        }
        
        return mp[key] = ans % 1003 ;
    }

    int countWays(int N, string S){
        // code here
        
        int i = 0 , j = N - 1; 
    
    bool isTrue = true ;
    
    int res = 0 ;
    
    unordered_map<string , int> mp ;
    
    
    
    res = helper(i , j , S , mp , isTrue) ;
    
    mp.clear() ;
    return res ;
    
    }

