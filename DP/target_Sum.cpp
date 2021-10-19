/*
https://leetcode.com/problems/target-sum/

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.


*/

class Solution {
private:
    int subsetSumCount(vector<int> &nums , int n , int sum)
    {
        int dp[n + 1][sum + 1] ;
        for(int i = 0 ; i < sum + 1 ; i++)
            dp[0][i] = 0 ;
        
        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = 1 ;
        
        for(int i = 1 ; i < n + 1 ; i++)
        {
            for(int j = 0 ; j < sum + 1 ; j++)
            {
                if(nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j] ;
                    
                }
                else
                    dp[i][j] = dp[i - 1][j] ;
                
            }
        }
        
        return dp[n][sum] ;
        
    }
    
    
    
    
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        int sum = 0 ;
        for(auto x:nums)
        {     
            sum += x;
            
        }
        if(sum < target || (sum+target)%2 != 0 || (sum+target)<0)
            return 0;
        
        int new_target = (sum + target)/2 ;
        
        return subsetSumCount(nums , n , new_target ) ;
    }
};