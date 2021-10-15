/*
https://www.interviewbit.com/problems/0-1-knapsack/

Problem Description

Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:

You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
int n = B.size() ;

int t[n+1][C+1] = {-1} ; 

for(int i = 0 ; i < n + 1 ; i++)
for(int j = 0 ; j < C + 1 ; j++)
{
    if(i == 0 || j == 0)
        t[i][j] = 0 ;
}

for(int i = 1 ; i < n+1 ; i++)
{
    for(int j = 1 ; j < C + 1 ; j++)
    {
        if(B[i - 1] <= j)
        {
            t[i][j] = max( A[i - 1] + t[i - 1][j - B[i - 1]] , t[i - 1][j] ) ; 
        }

        else
            t[i][j] = t[i - 1][j] ;


    }
}

return t[n][C] ;

}
