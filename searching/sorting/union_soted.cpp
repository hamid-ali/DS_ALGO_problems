// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//arr1,arr2 : the arrays
// n, m: size of arrays
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector <int> res; bool empty = true;//to handle empty vector initially as .back() throws an error
    int i = 0 , j = 0 ;
    while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
        {   if(empty || arr1[i] != res.back())
            res.push_back(arr1[i]);
            i++ ; j++ ;
        }
        else if( arr1[i] < arr2[j])
        {   if(empty || arr1[i] != res.back())
            res.push_back(arr1[i]);
            i++;
        }
        else
        {   if(empty || arr2[j] != res.back())
            res.push_back(arr2[j]);
            j++;
            
        }
        
        empty = false;
    }
    
    while(i < n){ if(empty || arr1[i] != res.back()) res.push_back(arr1[i]); i++;}
    while(j < m){if(empty ||  arr2[j] != res.back()) res.push_back(arr2[j]); j++; }
    
    return res;
}

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    vector<int> ans = findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends