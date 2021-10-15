/* https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int size = a.size();
        int prev = a[0] ,count = 0 ;
    
    for(int i = 0 ; i < size ; i++)
    {
        if(a[i] == prev)
        {   
            count++;
        
        }
        
        if(a[i] != prev)
        {
            if(count == 1)
                prev = a[i] ;
            else count--;
        }
    }
    
    if(count < 1) return -1;
    
    count = 0 ;
    
    for(int i = 0 ; i < size ; i++)
    {
        if(prev == a[i]) count++;
    }
    
    if(count > size/2) return prev;
    
    return  -1;
        
    }
};