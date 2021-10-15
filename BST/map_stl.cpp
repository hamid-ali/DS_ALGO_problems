#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int , int> mp = {{10, 100} , {3 , 300}};
    // mp.insert({10, 100} , {3 , 300});
    for(auto x:mp)
        cout<<x.first<<" "<<x.second<<endl ;

    return 0 ;



}