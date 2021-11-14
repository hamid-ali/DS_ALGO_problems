/*
https://www.interviewbit.com/problems/egg-drop-problem/


*/

int helper(int e , int f , vector<vector<int>> &t)
{
    if(f == 0 || f == 1)
    {
        return f ;
    }
    if(e == 1)
    {
        return f ;
    }

    if(t[e][f] != -1)
    {
        return t[e][f] ;
    }
    int mn = INT_MAX ;

    for(int k = 1 ; k <= f ; k++)
    {
        int low , high ;

        if(t[e - 1][k - 1] != -1)
        {
            low = t[e - 1][k - 1] ;
        }
        else
        {
            low = helper(e - 1 , k - 1 , t);
            t[e - 1][k - 1] = low ;
        }

        if(t[e][f - k] != -1)
        {
            high = t[e][f - k];
        }
        else
        {
            high = helper(e , f - k , t) ;
            t[e][f - k] = high ;
        }

        mn = min(mn , 1 + max(low , high));

    }

    return t[e][f] = mn ;

}



int Solution::solve(int e, int f) {

    vector<vector<int>> t(e + 1 , vector<int>(f + 1, -1)) ;

    return helper(e , f , t); 

}
