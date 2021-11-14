#include<bits/stdc++.h>

using namespace std;

vector<int> x_axis = {0 , 0 , -1 , 1};
vector<int> y_axis = {1 , -1 , 0 , 0};

bool notInfected(vector<string> &mat ,int row , int col){
    for(int i=0 ; i<row; i++)
        for(int j =0 ; j<col ; j++)
            if(mat[i][j] == '1' || mat[i][j] == '2')
               return true;
               
    return false;
}

bool isvalid(vector<string> &mat ,int row , int col , int x , int y){

    if(x>=0 && x<row && y>=0 && y<col){
        if(mat[x][y] == '2'){
            mat[x][y] = '1';
            return true;
        }
        else if(mat[x][y] == '1'){
            mat[x][y] = '0';
            return true;
        }
    }
        return false;
}

int helper(vector<string> &mat ,int row , int col)
{
    queue<pair<int , int>> q;
    for(int i=0 ; i<row; i++)
        for(int j =0 ; j<col ; j++)
            if(mat[i][j] == '0')
                q.push(make_pair(i , j));
    
    int count = 0;

    while(!q.empty()){
        int n = q.size();
        for(int i=0 ; i<n ; i++){
            int x = q.front().first;
            int y = q.front().second;
            char top = mat[x][y];
            q.pop();
            if(top == '0'){
                for(int j =0 ; j<4 ; j++){
                    int x_new = x+x_axis[j];
                    int y_new = y+y_axis[j];
                    if(isvalid(mat , row , col , x_new , y_new))
                        q.push(make_pair(x_new , y_new));
                    
                }
            }
            else if(top == '1')
            {
                q.push(make_pair(x , y));
                mat[x][y] = '0';
            }
           
        }
        count++;
    }
    
    if(notInfected(mat , row , col))
        return -1;
    return count-1;
}

int main()
{
    int t ;
    cin>>t;
    
    while(t--)
    {
        int row , col ;
        
        cin>>row;
        cin>>col;
        
        vector<string> mat(row) ;
        
        for(int i = 0 ; i < row ;i++)
        {
           cin>>mat[i];
        }
        
       int ans = helper(mat , row , col);
       cout<<ans<<endl;
    }
    return 0 ;
}