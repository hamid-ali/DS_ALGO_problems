#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

public:
    //Function to find whether a path exists from the source to destination.
    vector<int> diff_x = {0 , 1 , -1 , 0 };
    vector<int> diff_y = {1 , 0 , 0 , -1 } ;
    
    bool isValid(int i , int j , int &M , int &N , vector<vector<int>> &grid , vector<vector<bool>> &visited)
    {
        return (i >=0 && i < M && j >=0 && j < N && grid[i][j] != 0 && !visited[i][j]);
    }
    
    bool dfsRec(int i , int j , vector<vector<int>> &grid , int &M , int &N , vector<vector<bool>> &visited)
    {
       
        visited[i][j] = true ;
        if(grid[i][j] == 2)
        {
            return true ;
        }
       
        if(grid[i][j] != 0){
        for(int k = 0 ; k < 4 ; k++)
        {
            int new_x = i + diff_x[k] ;
            int new_y = j + diff_y[k] ;
            
            if(isValid(new_x , new_y , M , N , grid , visited) )
            {
                
                if(dfsRec(new_x , new_y , grid , M , N , visited))
                    return true;
            }
        
        }
        return false ;
        
        }
        
    }
    
    
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int M = grid.size() , N = M;//grid[0].size() ;
        
        vector<vector<bool>> visited(M , vector<bool>(N , false )) ;
        
        for(int i = 0 ; i < M ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(grid[i][j] == 1)
                {
                    
                    return dfsRec(i , j , grid , M , N , visited);
                    
                
                }
            }
        }
        
        return false ;
        
    }
};






//working is below one
class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    vector<int> diff_x = {0 , 1 , -1 , 0 };
    vector<int> diff_y = {1 , 0 , 0 , -1 } ;
    
    bool isValid(int i , int j , int &N , vector<vector<int>> &grid , vector<vector<bool>> &visited)
    {
        return (i >=0 && i < N && j >=0 && j < N && grid[i][j] != 0 && !visited[i][j]);
    }
    
    bool dfsRec(int i , int j , vector<vector<int>> &grid , int &N , vector<vector<bool>> &visited)
    {
       
       visited[i][j] = true ;
       
        if(grid[i][j] == 2)
        {
            return true ;
        }
       
        
        if(grid[i][j] != 0){
            for(int k = 0 ; k < 4 ; k++)
            {
                int new_x = i + diff_x[k] ;
                int new_y = j + diff_y[k] ;
                
                if(isValid(new_x , new_y , N , grid , visited) )
                {
                    
                    if(dfsRec(new_x , new_y , grid , N , visited))
                        return true;
                }
            
            }
            return false ;
        }
    }
    
    
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int N = grid.size() ;//grid[0].size() ;
        
        vector<vector<bool>> visited(N , vector<bool>(N , false )) ;
        
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(grid[i][j] == 1)
                {
                    
                    return dfsRec(i , j , grid , N , visited);
                    
                
                }
            }
        }
        
        return false ;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends