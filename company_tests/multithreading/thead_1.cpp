#include<bits/stdc++.h>
using namespace std ;

void print(int n, const std::string &str)  {  
    std::cout << "Printing integer: " << n << std::endl;  
    std::cout << "Printing string: " << str << std::endl;  
} 



int main() {
    std::thread t1(print, 10, "Educative.blog");
    t1.join();
return 0;
}