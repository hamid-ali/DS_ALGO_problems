/*

input: n = 9 , bit_pos = 1 , flag = true //set/unset
o/p : 1001 -> 1001 

*/

// #include<iostream> 
// using namespace std;

// void fun(int n , int bit_pos , bool flag)
// {
// 	unsigned int i = 1 ;

// 	i = i << bit_pos ;

// 	if(flag)
// 	{
// 		cout<<(n | i)<<endl; i = 1<<4 -> 10000 = 1
// 	}
// 	else
// 	{
// 		cout<<(n & ~i)<<endl; // i << 4 -> ~(10000) -> ...1111101111
// 	}
// 			n ^ i // 0 ^ 1 = 1 ; 1 ^ 1 = 0 


// }

// int n = oxFFFF 

// (i/p)map -> phyical //  

#include <stdio.h>

/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

struct st
{
  	int         i;

	short int   s;
  char        c,
 
} st_var;


/*Main function to call above function for 0x01234567*/
int main()
{
// int i = 0x01234567;
// show_mem_rep((char *)&i, sizeof(i));
// getchar();

printf("size of str is %u ", sizeof(st_var));

return 0;
}
