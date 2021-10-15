// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//arr1,arr2 : the arrays
// n, m: size of arrays
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector <int> res; bool empty = true;
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
        {   if(empty ||arr2[j] != res.back())
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

//GFG Naive approach for printing  union of sorted arrays
// O(m+n*log(m+n))  time and O(m+n) aux space

void printUnion(int a[], int b[], m , n)
{
    int c[m+n] ;

    for(int i = 0 ; i < m ; i++) c[i] = a[i] ;

    for(int i = 0; i < n ; i++) c[m + 1 + i] = b[i];

    sort(c , c + m + n);

    for(int i = 0 ; i < m+n; i++)
    {
        if(i == 0 || c[i] != c[i-1] )
            cout<< c[i] << " ";

    }
}

//More efficient linear time i. e. O(m+n) and O(1) aux space solution :--

void printUnion(int a[], int b[], int m , int n)
{
    int i = 0 , j = 0;

    while(i < m && j < n)
    {
        if(i > 0 && a[i] == a[i-1] ) {i++ ; continue; }

        if(j > 0 && b[j] == b[j-1]) {j++ ; continue ; }

        if(a[i] < b[j])  {cout << a[i] <<" " ; i++; }

        else if ( b[j] < a[i] ) { cout << b[j] <<" " ; j++ ;  }

        else
        {
            cout << a[i] << " ";  i++; j++;
        }
    }

    while(i < m) 
    {   if(i == 0 || a[i] != a[i-1]) 
            cout<<a[i]<<" " ; i++; 
    }

    while(j < n)
    {
        if(j == 0 || a[j] != a[j-1])
            cout << b[j] << " ";
        j++;
    }

}