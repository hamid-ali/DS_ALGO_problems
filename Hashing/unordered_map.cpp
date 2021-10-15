#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string , int> m ;
    

    m["Hamid"] = 11121996;

    m["Sabir"] = 26012010;

    m.insert({"Zahid" , 16}) ;

    for(auto x : m)
        cout<<x.first<<"  "<<x.second<<endl;
    

    if( m.find("Hamid") != m.end() )
        cout<<"Key is found and the value is "<<m["Hamid"]<<endl;

    else
    {
        cout<<"Key is not found";
    }
    
    // for(auto it = m.begin() ; it != m.end() ; it++)
    // {
    //     cout<< it->first<<"   "<<it->second<<endl ;

    // }
    
    if(m.count("Zahid"))
        cout<<"Zahid is there hence count is one  " <<endl;    
    else
    {
        cout<<"Zahid is not there. "<<endl;;
    }

    cout<<m.size()<<endl;

    m.erase("Zahid");

    if(m.count("Zahid"))
        cout<<"Zahid is there hence count is one  " <<endl;    
    else
    {
        cout<<"Zahid is not there. "<<endl;;
    }

    cout<<m.size();
    
    

    return 0;

}