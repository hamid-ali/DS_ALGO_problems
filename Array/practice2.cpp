#include<bits/stdc++.h> 

using namespace std;

void convert_to_words(string data, string dest)
{   string res[];
    for(int i=0; i < data.size() ; i++){
        if(data[i] == "4") res[i] = "four";
        else if(data[i] == "5") res[i] = "five";
        else if(data[i] == "6") res[i] = "six";
        else if(data[i] == "7") res[i] = "seven";
    }
    dest = &res;

}

int main()
{
 string data="4567";
 string dest[16];
 convert_to_words(data,dest);
 cout<<data<<endl;   
 for(int i=0;i<dest.();i++)
    cout<<dest[i];

}