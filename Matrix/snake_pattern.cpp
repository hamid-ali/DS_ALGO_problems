void sPrint(int mat[R][C])
{   
    for(int i = 0 ; i < m ; i++)
    {
            if(i%2 == 0)
            {
                for(int j = 0 ; j < n ; j++)
                cout<<mat[i][j];<<" ";

            }
            else
            {
                cout<<endl;
                for(int i = n-1 ;i >=0 ; i--)
                {
                    cout<<mat[i][j]<<" ";
                }
            }
            cout<<endl;
    }
}