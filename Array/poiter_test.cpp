#include<iostream>

using namespace std;

void mask_vowels(string mesg , string res )
{   int i=0;
    while(mesg[i] != "\0"){
        if(mesg[i] == "a" || mesg[i] == "e"  || mesg[i] == "i"  || mesg[i] == "o" ||mesg[i] == "u" )
            res.append("*");
        
        else res.append(mesg[i]);
        i++;
    }
}

int main(){
  string mesg="hello world of unix was the output";
  string  res;
  mask_vowels(mesg,res);
  cout<<mesg<<endl;   
  cout<<res<<endl ;  
}