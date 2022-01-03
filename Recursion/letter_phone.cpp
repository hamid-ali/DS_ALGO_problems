/*
Given a digit string A, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself. The digit 1 maps to 1 itself.

NOTE: Make sure the returned strings are lexicographically sorted.
Example Input

Input 1:

 A = "23"
Input 2:

 A = "012"


Example Output

Output 1:

 ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
Output 2:

 ["01a", "01b", "01c"]




*/

vector<string> mp = {

"0", "1" ,"abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" ,"wxyz" } ;

void helper(string &A , int idx , vector<string> &res , string curr )

{

if(idx == A.size())

{

res.push_back(curr);

return ;

}

for(int i = 0 ; i < mp[(A[idx]) - '0'].length() ; i++)

{

curr = curr + mp[(A[idx] - '0')][i] ;
helper(A , idx + 1 , res , curr );
curr.pop_back();

}

}

vector<string> Solution::letterCombinations(string A) {

vector<string> res ;

helper(A , 0 , res , "");

return res ;

}