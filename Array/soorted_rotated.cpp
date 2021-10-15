// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// arr: input array
// num: length of array
// This function returns true or false
bool checkRotatedAndSorted(int arr[], int num)
{
    int max = arr[0] , min = arr[0];
     
    int i; bool flag = false;
    
    if(num == 1 || num == 2) return true;
    
    for( i = 0 ; i < num ; i++ )
    {
        if(arr[i] <= min) min = arr[i] ;
        
        if(arr[i] >= max) max = arr[i] ;
        
    }
    
    
    for( i = 0 ; i < num-1 ; i++)
    {
        if(arr[i] <= arr[i+1]) continue;
        else if(arr[i] == max) 
        {  
            flag = true;
            continue;
            
        }
        break;
    }
    
    if( i == num-1 && flag == true && arr[num-1] < arr[0]) return true;
    
    flag = false;

    
    for( i=0 ; i < num-1 ; i++)
    {
        if(arr[i] >= arr[i+1]) continue;
        else if(arr[i] == min)
        { 
            flag = true;
            continue;
            
        }
        break;
    }
    
    if( i == num-1 && flag == true && arr[num-1] > arr[0] ) return true ;
    
    return false;
    
}

// { Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        
        //function call
        flag = checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
} 