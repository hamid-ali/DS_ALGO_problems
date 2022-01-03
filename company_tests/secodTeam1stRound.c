#include<stdio.h>

struct my_struct{
	long long int n ;
	char ch ;
	
};

int main(){
    
    struct my_struct st ;
    
    printf("size of my struct st is %ld \n" , sizeof(st));
    
    return 0 ;
    
}