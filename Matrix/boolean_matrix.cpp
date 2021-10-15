// { Driver Code Starts

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {   
        int row = matrix.size() , column = matrix[0].size() ;
        
        for(int i = 0 ; i < row ; i++)
        {   
            for(int j = 0 ; j < column ; j++)
            {
                if(matrix[i][j] == 1) 
                {   if(matrix[i][0] == 1)
                    {   if(j == 0 && i == 0)
                        matrix[i][0]++;
                        break;
                    }
                    
                    else
                        {
                            matrix[i][0]++;
                        
                            break;
                        }
                }
                
            }   
        }
        
        for(int j = 0 ; j <  column ; j++)
        {
            for(int i = 0 ; i < row ; i++)
            {   
                if(matrix[i][j] == 1)
                {
                    if(matrix[0][j] == 1)
                    {
                        if(j == 0 && i == 0)
                            matrix[0][j]++;
                        break;
                    }
                    
                    else { matrix[0][j]++; break ;}
                    
                }
            
            }
            
        }
        
        for(int i = 0 ; i < row ; i++)
        {   
                if(matrix[i][0] >= 1)
                {
                    for( int j = 1 ; j < column ; j++)
                    {   
                        // if(j == 0) continue;
                        matrix[i][j] = 1;
                    }
                    
                }
                
                
            
        }
        
        for(int j = 1 ; j < column ; j++)
        {
            if(matrix[0][j] == 1)
            {
                for( int i = 0 ; i < row ; i++)
                {       
                        matrix[i][j] = 1;
                }
            }
        }
        
        if(matrix[0][0] > 1)
        {
            for(int i = 0 ; i < row ; i++)
            matrix[i][0] = 1;

            for(int j = 0 ; j < column ; j++)
            matrix[0][j] = 1;
        }

        else if(matrix[0][0] == 1)
        {
            for(int j = 0 ; j < column ; j++)
            matrix[0][j] = 1;
        }
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


  // } Driver Code Ends