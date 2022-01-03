#include <stdio.h>

void fun(void){
  int *p ;
  int a = 0x3;
  int b = 0x5;
    
    p = (int*)malloc(sizeof(int));
    if(p == NULL)
        return ;
    *p = (a++) + (++b);
    printf("%d" , *p) ;// 3 + 6 = 9 
    free(p);
}


struct myStruct{
    //4 byte
     char c ;
    char a ;
    int b ;
 };
 
 union myUnion{
    
     int b ;
     char c ;
     char a ;
 };

int main(){
                printf("this prog will print size of a struct with int , char and char \n");

                struct myStruct st;

                printf(" %ld \n", sizeof(st));
                
                union myUnion mn ;
                
                printf("Below is size of union with int , char , char \n");
                
                printf("%ld \n", sizeof(mn));
                
                
                mn.b = 1;
                
                mn.a = 3;
                mn.b = 5 ;
                mn.c = 'A';
                printf("%d \n" , mn.b);

                char arr[100][100] = {'a'} ; //&arr[0] = 100

               printf("Address of arr is %u and Address of arr[45][50] is %u \n", arr , &arr[45][50]) ;

                fun();


                return 0;

}