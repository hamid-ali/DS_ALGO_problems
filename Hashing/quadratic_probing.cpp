// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void QuadraticProbing(vector <int> &hash, int hashSize,int arr[],int sizeOfArray);

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
	    
	    vector<int> hash (hashSize);
	    
	    QuadraticProbing (hash, hashSize, arr, sizeOfArray);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}

// } Driver Code Ends


// Insert all the element of array arr[] (size N)
// fill the hash table hash[] (size hashSize)
void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
{
    fill(hash.begin() , hash.end() , -1);
        
    for(int i = 0 ; i < N ; i++)
    {   
        int pos = arr[i] % hashSize;
        
        
         for(int j=1; hash[pos]!=-1; j++)
            pos = (arr[i]+j*j)%hashSize;
        
        hash[pos] = arr[i];
        
        
    }
}

