/*
Unsorted is a data type in STL of C++.
Its similar to set but different in implememtation as its based on Hashing.

Available functions:-
insert() , begin() , end() , size() , clear() , find() 




*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s;
    
    s.insert(10) ;
    s.insert(20);
    s.insert(5);
    s.insert(15);
    for( int x : s)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto it = s.begin() ; it != s.end() ; it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;

    if(s.find(25) != s.end())
    {
        cout<<"25 is found in hash table"<<endl;

    }
    else
    {
        cout<<"25 is not found"<<endl;
    
    }
    cout<< * s.find(20) <<endl;

    s.insert(15);

    cout<<s.count(15)<<endl;  //it will always return 1 or 0 as duplicates are not there in unordered set

    if(s.count(15))
        cout<<"found"<<endl;

    else
        cout<<"Not found"<<endl;


    cout<<s.size()<<endl;

    s.erase(15);
    cout<<s.size()<<endl;

    auto it = s.find(10);
    s.erase(it);

    cout<<s.size()<<endl;

    //s.clear();                  //it empties the container which might be desired to begin new test cases.
    
    s.erase(s.begin() , s.end()) ;  //its same as s.clear()

    cout<<s.size()<<endl;

    return 0;

}