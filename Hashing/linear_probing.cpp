// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> linearProbing(int hashSize,int arr[],int sizeOfArray);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    vector<int> hash;
	    
	    hash = linearProbing( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

// } Driver Code Ends


//Complete this function

vector<int> linearProbing(int hashSize, int arr[], int N)
{
    vector<int> res(hashSize , -1) ;
    
    for(int i = 0 ; i < N ; i++)
    {
        int pos = arr[i] % hashSize ;
        
        if(res[pos] == -1) res[pos] = arr[i] ;
        
        else
        {
            int pos_copy = pos;
            while(res[pos] != -1 )
            {
                if((pos + 1) % hashSize == pos_copy ) break;
                pos = (pos + 1) % hashSize;
            }
            if(res[pos] == -1)
            res[pos] = arr[i] ;
        }
    }
    
    return res;
    
}
