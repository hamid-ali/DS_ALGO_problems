/ { Driver Code Starts
// C++ program to find union of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

vector<int> printIntersection(int arr1[], int arr2[], int N, int M);  
  
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        
        // Function calling 
        vector<int> v;
        v = printIntersection(arr1, arr2, N, M); 
        
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";

        cout << endl;
    }
    
  return 0; 
} 
// } Driver Code Ends


/* Function prints Intersection of arr1[] and arr2[] 
N is the number of elements in arr1[] 
M is the number of elements in arr2[] 
Return the array
*/
vector<int> printIntersection(int arr1[], int arr2[], int n, int m) 
{ 
    vector <int> res; bool empty = true;//to handle empty vector initially as .back() throws an error
    int i = 0 , j = 0 ;
    while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
        {   if(empty || arr1[i] != res.back())
            res.push_back(arr1[i]);
            empty = false;
            i++ ; j++ ;
        }
        else if( arr1[i] < arr2[j])
        { 
            i++;
        }
        else
        {   
            j++;
            
        }
        
    }
    
    return res;
}

//GfG way of implementataion

void intersection(int a[] , int b[] , int m , int n)
{
    for(int i = 0 ; i < m ; i++)
    {
        if(i > 0 && a[i] = a[i - 1])
            continue;
        for(j = 0 ; j < n ; j++)
        {
            if(a[i] == b[j])
                cout << a[i] << " ";
        }
    }



}