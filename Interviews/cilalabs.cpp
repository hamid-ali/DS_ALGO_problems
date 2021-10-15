#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int foo(int param[] , int n) {
  
  int temp = param[0] ;
  vector<int> min_so_far(n , temp);
  for(int i = 1 ; i < n ; i++ )
  {
    min_so_far[i] = min(min_so_far[i - 1] , param[i]) ;
  
  }
int max_diff = INT_MIN ;
for(int i = n - 1 ; i > 0 ; i--)
{
  if(param[i] - min_so_far[i-1] > 0)
  max_diff = max(max_diff , (param[i] - min_so_far[i-1])) ;
}

if(max_diff > 0) return max_diff;
  return -1;
}

int main() {
  int arr[4] = {10, 9, 8, 2} ;



  cout << foo(arr, 4);
  return 0;
}


