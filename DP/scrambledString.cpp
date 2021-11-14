/*
https://www.interviewbit.com/problems/scramble-string/
Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.



Given two strings A and B of the same length, determine if B is a scrambled string of S.



Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= len(A), len(B) <= 50
Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

*/

bool helper(string a , string b , unordered_map<string , bool> &mp)
{
    if(a.compare(b) == 0)
        return true;
    if(b.length() <= 1 )
        return false ;

    int n = a.length() ;

    string key = a + " " + b ;

    if(mp.find(key) != mp.end())
    {
        return mp[key] ;
    }

    bool flag = false ;
    for(int i = 1 ; i < n ; i++)
    {
        bool flag1 , flag2 , flag3 , flag4 ;

        string s1 = a.substr(0 , i) ,
                s2 = b.substr(n - i , i) ,
                s3 = a.substr(i , n - i) ,
                s4 = b.substr(0 , n - i) ,

                s5 = b.substr(0 , i) ,
                s6 = b.substr(i , n - 1);

        if(mp.find(s1+" "+s2) != mp.end())
            {
                flag1 = mp[s1+" "+s2] ;

            }
        else
        {
            flag1 = helper(s1 , s2 , mp) ;
            mp[s1+" "+s2] = flag1 ;
        }

        if(mp.find(s3 + " " + s4) != mp.end())
        {
            flag2 = mp[s3 + " " + s4];

        }
        else
        {
            flag2 = helper(s3 , s4 , mp);

            mp[s3+" " + s4] = flag2 ;
        }


        if(mp.find(s1 + " " + s5) != mp.end())
        {
            flag3 = mp[s1+ " " + s5] ;

        }
        else
        {
            flag3 = helper(s1 , s5 , mp) ;
            mp[s1 + " " + s5] = flag3 ;
        }

        if(mp.find(s3 + " " + s6) != mp.end() )
        {
            flag4 = mp[s3 + " " + s6] ;
        }
        else
        {
            flag4 = helper(s3 , s6 ,mp) ;
            mp[s3 + " " + s6] = flag4 ;
        }


        if((flag1 && flag2) || (flag3 && flag4) )
        {
            flag = true ;
            break ;
        }

     
    }

     return mp[key] = flag ;

}



int Solution::isScramble(const string A, const string B) 
{
    unordered_map<string , bool> mp ;
    
    if(helper(A , B , mp) == true)
        return 1;

    return 0 ;


}

