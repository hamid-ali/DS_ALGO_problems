#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<class T, class CMP>
void sorting(T a[], const int SIZE, CMP compare) {
 int i, j;
 for (i = 0; i < SIZE; i++)
  for (j = i + 1; j < SIZE; j++)
   if (compare(a[i], a[j]))
    swap(a[i], a[j]);
}

int getindex(string args) {
 string known[] = { "mon", "sun", "tue", "wed", "thu", "fri", "sat" };
 for (int i = 0; i < 7; i++) {
  if (known[i] == args)
   return i;
 }
 return -1;
}
bool comparator(string a, string b ){
 if (getindex(a) > getindex(b) )
  return true;
 else
  return false;
}
int main() {
 string weeks[] = { "sat","mon","wed","tue","sun","thu","fri" };
 sorting(weeks, 7, comparator);
 for (int i = 0; i < 7; i++) {
  cout << weeks[i] << endl;
 }
}