/*
Given a string generate its all subsets.
Here we are writing iterative soln based on binary representation of a  no with len(string)
bits
*/

#include<bits/stdc++.h>

using namespace std;

void printPowerSet(string str)
{
    int n = str.length();
    int powSize = pow(2 , n);

    for(int counter = 0 ; counter < powSize ; counter++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(counter & (1 << j))
                cout<<str[j];
        }

        cout<<endl;

    } 


}

int main()
{
    int t ;
    cin>>t;

    while(t--)
    {
        string str;
        cin>>str;

        printPowerSet(str) ;

    }



}