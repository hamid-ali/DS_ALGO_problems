// { Driver Code Starts


#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends




class Solution
{   
public:  
    
    void f(std::vector<std::reference_wrapper<int>>) {}
    
    void boundaryTraversal(vector<vector<int> > matrix, int r, int c , vector<int> &res , int offset) 
    {   int n = matrix.size() , m = matrix[0].size() ;
        // vector<int> res ;
    
        if(r < 1 || c < 1) return;
        if(r  == 1)
        {
            for(int i = 0 ; i < c  ;i++)
                res.push_back(matrix[0 + offset][i + offset]);
                
        }
        
        else if(c == 1)
        {
            for(int i = 0 ; i < r  ;i++)
                res.push_back(matrix[i + offset][0 + offset]);
                
        }
        else
        {
            for(int j = 0 ; j < c   ; j++)
            {
                res.push_back(matrix[0 + offset][j + offset]);
            }
            
            for(int i = 1 ; i < r  ; i++ )
            {   
                res.push_back(matrix[i + offset][m-1 - offset]) ;
                
            }
            
            for(int j = c - 2  ; j >= 0  ; j--)
            {
                res.push_back(matrix[n - 1 - offset][offset + j]);
                
            }
            
            for(int i = r - 2  ; i >= 1  ; i--)
            {
                res.push_back(matrix[offset + i][0 + offset]);
            }
            
        }
        
        // return res;
        
    }
    
    void helper(vector<vector<int> > matrix, int r, int c , vector<int> &res , int offset)
    {
        if(r >= 1 || c >= 1 )
        {
            boundaryTraversal(matrix , r , c , res , offset);
            
            helper( matrix , r - 2 , c - 2 , res , offset + 1 );
        }
        
        // return;
        
    }
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {  
        vector<int> res;
        
        int offset = 0;
        
        helper(matrix , r , c , res , offset);
        
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends