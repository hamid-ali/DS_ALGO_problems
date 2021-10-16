/* https://www.interviewbit.com/problems/subset-sum-problem/

Problem Description

Given an integer array A  of size N.

You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

If there exist a subset then return 1 else return 0.

*/


// int helper(vector<int> &A , int B , int n , int t[][100001])
// {
//     if(B == 0)
//     {
//         return 1 ;
//     }
//     if(n == 0)
//     {
//         return 0 ;
//     }

//     if(t[n][B] != -1)
//         return t[n][B] ;

//     if(A[n - 1] <= B)
//     {
//         return  t[n][B] = max(helper(A , B , n - 1 ,t) , helper(A , B - A[n -1] , n -1 , t) ) ;
//     }

//     return  t[n][B] = helper(A , B , n - 1 , t) ;


// }

int Solution::solve(vector<int> &A, int B) {
    int n = A.size() ;

    int t[n + 1][B + 1] ;

    //memset(t , - 1 , sizeof(t)) ;
for(int i = 0 ; i < B + 1 ; i++)
    {
        t[0][i] = 0;
    }
    for(int i = 0 ; i < n + 1 ; i++)
    {
        t[i][0] = 1;
    }


    for(int i = 1 ; i < n + 1 ; i++)
    {
        for(int j = 1 ; j < B + 1 ; j++)
        {
            if(A[i-1] <= j )
            {
                t[i][j] =  t[i - 1][j - A[i-1]] || t[i -1][j] ;
                
            }
            else
            {
                t[i][j] = t[i - 1][j] ;
            }

        }
    }

    return t[n][B] ;

}