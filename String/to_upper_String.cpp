#include<bits/stdc++.h>
using namespace std;

int main()
{
    string su = "Hamid Ali" ;

    transform(su.begin() , su.end() , su.begin() , ::tolower ) ;

    cout<<"losercase version of given string is  "<<su<<endl;

    transform(su.begin() , su.end() , su.begin() ,::toupper) ;

    cout<<"uppercase version of given string is  "<<su<<endl ;


    return 0;


}