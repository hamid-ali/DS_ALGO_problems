#include <iostream> 

using namespace std;

int add(int a, int b)      { return a + b; }
int minusit(int a, int b)  { return a - b; }
int divide(int a, int b)   { return a / b; }
int multiply(int a, int b) { return a * b; }

int callback(int (*fnptr)(int,int), int arg1, int arg2)
{
   int ans;
   cout<<"Specially called\n";
   ans = fnptr(arg1,arg2);
   return ans;
}


int main(){
  cout<<"ADD Direct = "<<add(10,20)<<endl;
  
  cout<<"ADD via call back "<<callback(add,10,20)<<endl;
  cout<<"MUL via call back "<<callback(multiply,10,20)<<endl;

}
