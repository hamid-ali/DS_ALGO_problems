Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    cout<<subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}// } Driver Code Ends


int subArraySum(int arr[], int n, int sum)
{
    unordered_map<int, int> prevSum;

        int res = 0;
        int currsum = 0;
        
        for (int i = 0; i < n; i++) {
        
        currsum += arr[i];
        
        if (currsum == sum)
        res++;
        
        if (prevSum.find(currsum - sum) !=prevSum.end())
        res += (prevSum[currsum - sum]);
        
        prevSum[currsum]++;
        }
        
        return res;

}