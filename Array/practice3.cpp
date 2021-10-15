#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

#include<iostream>
#include<string>       //  stoi - string to integer  C++11 feature
#include<cstdlib>
#include<cstdio>

using namespace std;

typedef struct Point {
 int x;
 int y;
}POINT;


template <typename T> 
T myMax(T x, T y) 
{ 
   return (x > y)? x: y; 
} 



void mysort(T a[], const int SIZE) {
 int i, j;
 for ( i = 0; i < SIZE; i++)
  for (j = i + 1; j < SIZE; j++)
   if (a[i] > a[j])
    swap(a[i], a[j]);

}

int main() {
  int arr[] = { 25,30,450,2 };
  mysort(arr,4);
  for (int i = 0; i < 4; i++)
   cout << arr[i]<<endl;

  POINT arr[] = {  };
  mysort(arr);
  for (int i = 0; i < 4; i++)
    cout << arr[i].x << " " << arr[i].y << endl;
    
}