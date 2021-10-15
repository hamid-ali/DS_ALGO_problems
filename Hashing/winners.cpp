// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

vector<string> winner(string arr[],int n);

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        
        vector<string> result = winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


// Funtion to find winner
// arr[]: input array
// n: size of array

vector<string> winner(string arr[],int n)
{
    // unordered_map<string , int> res;
    
    // for(int i = 0 ; i < n ; i++)
    // {
    //     if(res.count(arr[i])) res.find(arr[i])->second++;
    //     else
    //         res.insert({arr[i] , 1});
        
    // }
    
    // vector<string> winners;
    // int max_votes = INT_MIN; 
    // for(auto x:res)
    // {
    //     max_votes = max(max_votes,x.second) ;
    // }
    
    // for(auto x:res)
    // {
    //     if(x.second == max_votes) winners.push_back(x.first) ;
    // }
    
    // sort(winners.begin() , winners.end());
    // vector<string> final_res;
    // final_res.push_back(winners[0]);
    // final_res.push_back(to_string(max_votes));
    
    // return final_res;
    
    // map to store count of frequency of each name
        unordered_map<string,int>mp;
        
        
        // storing the frequency of names in the map
        for(int j=0;j<n;j++)
        {
            mp[arr[j]]++;
        }
        
        int maxx=-1;
        string answer="";
        
        // Iterating through the map to find the name with highest frequency
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>maxx)
            {
                maxx=it->second;
                answer=it->first;
            }
            else if(it->second == maxx && answer.compare(it->first) > 0)
                answer = it->first;
        }
        vector<string> vec = {answer,to_string(maxx)};
        return vec;
    
    
}