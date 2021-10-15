#include<iostream>

using namespace std;
class Base{
  int a;
 public:   
  Base(x=10):a(x){ cout<<"Ctor called\n"; }
  ~Base()        { cout<<"Dtor called\n"; }
  void minus()   { cout<<"we know how to substract\n";}
  virtual void add(){ cout<<"don't know to add\n"; }
};

class Derived:public Base{
  int b;
 public:   
  Derived(y=10):b(y){ cout<<"Derived Ctor called\n"; }
  ~Derived()        { cout<<"DErived Dtor called\n"; }
  void add()        { cout<<"Hey we got how to add\n"; }
  void mult()       { cout<<"cool mult\n"; }
  void divi()       { cout<<"awesome to divi\n"; }
};

int main(){
  Base *ptr = new Derived(5);
  ptr->add();
  ptr->minus();
  ptr->mult();
  ptr->divi