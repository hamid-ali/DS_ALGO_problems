#include<iostream>
using namespace std;

int main(){
int max1 = 0 ,max2 = 0;

int arr[5] = {5 , 4, 3 , 2, 1};
max1=arr[0];max2 = max1;
for(int i=0; i< 4 ;i++){
if(arr[i] >= max2){
    if(max1 < arr[i])
    max2 = max1;
    max1 = arr[i];
}
}


cout<<"2nd max is "<< max2;

}