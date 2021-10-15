#include <bits/stdc++.h>
using namespace std;

 int gcd(int a, int b)
{
    // start:  to optimise as its a tail recursive
	if(b==0)
		return a;

	return gcd(b, a % b);
    // int temp = b;
    // b = a % b;
    // a = temp;
    // goto start;
}

int main() {
    
    	int a = 100, b = 120;
    	
        int res = gcd(a, b);
    	cout<<res<<" is GCD"<<endl;

        cout<<"LCM is "<<(a*b)/res ;
    	
    	return 0;
}