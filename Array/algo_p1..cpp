#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


//transform(src.begin(), src.end(), dest.begin(), function_pointer)

// int increment(string a ) { return toupper(a);  }



int main(){
 string arr[]={"hello", "World", "of", "unix" };
 string temp[4];
 transform(arr, arr + 4, temp , temp+4, toupper);
 for (int i = 0; i < 4; i++)
 {
  cout << temp[i] << endl;
 }
}
/*string a[]={"hello", "World", "of", "unix" };

Expected:-
----------
HELLO
WORLD
OF
UNIX  */