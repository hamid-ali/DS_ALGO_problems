#include<bits/stdc++.h>
using namespace std;

struct test
{
    int x;
    bool operator <(const test &t) const
    {
        return (this->x > t.x) ;
    }

};

int main()
{
    set<test> s;
    s.insert({5}) ;
    s.insert({20}) ;
    s.insert({10}) ;
    for(test t:s)
        cout<<t.x<<" " ;
    
    return 0 ;

}