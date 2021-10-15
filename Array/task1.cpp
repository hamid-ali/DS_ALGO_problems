#include<iostream>
using namespace std;

class Myarray {
private:
 int* ptr;
 int size;
 int i;
public:
 Myarray(int s=5) { i = 0;  size = s; ptr = new int[size]; }
 void show() {
  for (i = 0; i < size; i++) cout << ptr[i] << " ";
  cout << endl;
 }

        // important type conversion operators
 operator int() { return size; }
 operator string() { string a = "hello world"; return a; }
};

int main()
{
 Myarray a1(10);
//  a1.set();
 a1.show();

 int res = a1;
 cout << "RES1 = " << res<<endl;
 
 string ans = a1;   
 cout << "ANS = " << ans << endl;
}
