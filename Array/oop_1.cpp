#include<iostream>
using namespace std;
// user defined Exception
// over-ridden method - void what()
class ZeroError {
 string mesg;
public:
 ZeroError(string m) :mesg(m) { }
 virtual void what() { cout << mesg << endl; }
};

int main() {
 int a, b, c;
 cout << "Enter a & b : ";
 cin >> a >> b;
 try 
 {
  if (a == 0 || b == 0) { throw new ZeroError("Hello zero"); }
  c = a + b;
  if(c < 0) throw 25;
  if (c < 10) throw "cannot be less than 10";
  cout << "REsult = " << c << endl;
 }
 catch (ZeroError* ex1) { cout << "Here\n";  ex1->what(); }
 catch (int& ex2) { cout << "cannot be -ve Int\n"; }
 catch (char* ex3) { cout << ex3 << endl; }
 catch (...) { cout << "GEneric\n"; }
}
