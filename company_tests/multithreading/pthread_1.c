#include<stdio.h>
#include<pthreads.h>
void myTurn(){
                while(1){
                        printf("my turn !\n") ;
                        sleep(1);
                        }


                }

void yourTurn(){
                while(1){
                        printf("your turn!\n");
                        sleep(1);
                }

int main(){

        myTurn();

        yourTurn();

        return 0 ;
        }