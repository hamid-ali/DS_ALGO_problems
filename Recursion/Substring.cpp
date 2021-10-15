#include<bits/stdc++.h>
using namespace std;

void printSubstring(string &str , int i = 0   , string res = "")
{
    if(i == str.length())
    {
        cout<<res<<endl ;
        return ;
    }

    printSubstring(str , i + 1 , res );

    printSubstring(str , i + 1 , res + str[i]) ;

}

int main(){
    string str;
    cout<<"Enter ur string"<<endl ;
    cin>>str;

    cout<<"printing all substrings below of "<<str<<endl ;

    printSubstring(str ) ;

    return 0 ;
}