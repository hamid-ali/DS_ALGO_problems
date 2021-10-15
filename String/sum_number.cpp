// { Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends


// Function to calculate sum of all numbers present
// in a string containing alphanumeric characters
int findSum(string str)
{
    int res = 0 , temp = 0 ;
    int n = str.length() ;
    int i = 0 ;
    while(i < n)
    {
        if(str[i] <= '9' && str[i] >= '0' )
        {   temp = str[i] - '0' ;
            i++ ;
            while(str[i] <= '9' && str[i] >= '0' && i < n)
            {
                temp = temp*10 + (str[i] - '0') ;
                i++;
                
            }
            
            res += temp ;
        }
        i++;
        // res += temp ;
    }
    
    
    return res ;
    
}

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout << findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends