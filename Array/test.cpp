// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to reverse the array in groups
vector<long long> reverseInGroups(vector<long long> &mv, int n, int k)
{
    vector<long long> result;
    int i = 0, k_counter = 0;

    for (i = 0; i < n - (n % k) ; i++)
    {
        if (i % k == 0)
            k_counter++;
        result.push_back(mv[(k * k_counter) - (i % k) - 1]);
    }

    int j = 0;
    if (i < n)
    {
        for (int l = i; l < n; l++)
        {
            result.push_back(mv[n - j - 1]);
            j++;
        }
    }
    return result;
}

// { Driver Code Starts.

int main()
{

    int t;    //Testcases
    cin >> t; //input the number of testcases

    while (t--)
    { //while testcases exist

        int n;
        cin >> n; //input the size of array

        vector<long long> mv; // Declaring a vector mv

        int k;
        cin >> k; //input k

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x; //input element of array

            mv.push_back(x); //push the element into vector
        }

        mv = reverseInGroups(mv, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << mv[i] << " "; //Just print the vector
        }

        cout << endl;
    }
}
// } Driver Code Ends