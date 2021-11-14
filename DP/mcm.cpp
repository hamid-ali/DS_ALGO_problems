/*
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000


*/

int helper(int i , int j , int arr[] , vector<vector<int>> &t)
    {
        if(i >= j)
        {
            return 0;
        }
        int mn = INT_MAX ;
        if(t[i][j] != -1)
        {
            return t[i][j] ;
        }
        for(int k = i ; k < j ; k++)
        {
            // int temp = helper(i , k , arr , t) + helper(k + 1 , j , arr , t)
            //             + arr[i - 1]*arr[k]*arr[j] ;
            int l , r ;
            
            if(t[i][k] != -1)
                l = t[i][k] ;
            else
                l = helper(i , k , arr , t) ;
                
            if(t[k + 1][j] != -1)
                r = t[k + 1][j] ;
                
            else
                r = helper(k + 1 , j , arr , t) ;
            
            mn = min(mn , (l + r + arr[i - 1]*arr[k]*arr[j]) );
        }
        
        return t[i][j] = mn ;
        
    }

    int matrixMultiplication(int N, int arr[])
    {
        if(N == 0 || N == 1)
        {
            return 0 ;
        }
        int i = 1 , j = N - 1 ;
        
        int res = 0 ;
        
        vector<vector<int>> t(N , vector<int>(N , -1)) ;
        
        res = helper(i , j , arr , t) ;
        
        return res ;
        
    }