#include<bits/stdc++.h>
using namespace std;

int main()
{
    // set<int , greater<int> > s;
    set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(20);

    auto it = s.lower_bound(5) ;
    if(it != s.end())
        cout<<(*it)<<endl;
    else
        cout<<"Given element is greater than the target";


    cout<<"crbegin is "<<*s.crbegin()<<" crend is "<<*s.crend()<<" rbegin is "<<*s.rbegin()<<" cbegin is "<<*s.cbegin()<<" rend is "<<*s.rend();

    return  0 ;

}