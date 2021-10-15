// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;

vector<int> findPairs(int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector <int> res = findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}// } Driver Code Ends


// User function template for C++

vector <int> findPairs(int arr[], int n) 
{
    unordered_map<int , int> number;
    vector<int> res;
    
    for(int i = 0 ; i < n ; i++)
    {
            if(arr[i] !=0){
            number[abs(arr[i])] += arr[i];
            if(number[abs(arr[i])] == 0)
                {
                    res.push_back(-1*abs(arr[i]));
                    res.push_back(abs(arr[i]));
                }
                
            }
    }
    
    return res;
}