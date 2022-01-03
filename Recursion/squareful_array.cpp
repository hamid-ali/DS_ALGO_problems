
// Alternate solution explained in the video 
bool isSquare(int x) {
    for(int i = 0 ; i*i <= x ; i++)
    {
        if(i*i == x)
            return true ;

    }
    return false ;
}



void generatePermutations(vector<int> nums, int &count , int idx )
{
    if(nums.size() == 1)
        return ;
    if(idx == nums.size() - 1)
    {
        if(isSquare(nums[idx - 1] + nums[idx]))
            count += 1 ;

        return ;
    }

    for(int j = idx ; j < nums.size() ; ++j)
    {
        if(j != idx && nums[j] == nums[idx])
        {
            continue;
        }
        swap(nums[j] , nums[idx]) ;
        if(j == 0 || (idx > 0 && isSquare(nums[idx] + nums[idx - 1])) )
        generatePermutations(nums ,count , idx + 1);

    }

    
}

int Solution::solve(vector<int> &A) {

    sort(A.begin() , A.end());

    int count = 0 ;
   
    generatePermutations(A , count , 0);

    return count ;

}