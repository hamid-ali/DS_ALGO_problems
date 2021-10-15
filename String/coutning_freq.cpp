#include<bits/stdc++.h>

using namespace std;

void printFreq(string str)
{
    int n = str.length() ;

    int freq[26] = {0} ;

    for(int i = 0 ; i < n ; i++)
    {
        freq[str[i] - 'a'] ++;
    }

    for(int i = 0 ; i < 26 ; i++)
    {
        while(freq[i])
        {
            cout<<char('a' + i)<<"  " ;
            freq[i]--;
        }
    }
}

int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        string str ;
        
        cin>> str ;

        printFreq(str) ;

    }

    return 0 ;
}