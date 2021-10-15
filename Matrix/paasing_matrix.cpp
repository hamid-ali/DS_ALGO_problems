/* Passing original/native 2-D array restricts the no. of rows and columns to be fixed prior to
passing it to function i.e. hard coded.

Work around to this is to either use double pointers or array of pointers for C style solution.

Or use vectors (STL) for C++ style soln for variable no of rows / & columns.





*/

//C style double pointer version of print function :-

// void print1(int **arr , m , n)
// {
//     for(int i = 0; i< m ; i++)
//     {
//         for(int j = 0 ; j < n ; j++)
//         {
//             cout<<arr[i][j]<<" " ;

//         }
//         cout<<endl;
//     }
// }


// //C style array of pointers version of print function:-

// void print2(int *arr[], int m , int n)
// {
//     for(int i = 0 ; i < m ; i++)
//     {
//         for(int j = 0; j < n ; j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// //C++ style array of vectors version of print function:-

// void print3(vector<int> arr[], int m)
// { for(int i= 0 ;; i < m ; i++)
//     { for(int j = 0; j < arr[i].size() ; j++)
//     {
//         cout<<arr[i][j]<<" ";

//     }
//     cout<<endl;
//     }
// }



#include<iostream>
#include<vector>
using namespace std;

void print4(vector< vector<int> > &arr);

int main(){
    
    vector< vector <int>> arr;          //vector of vectors to meke rows and columns both dynamic
    int m = 5 , n = 4;
    for(int i = 0 ; i < m ; i++ )
    {   
        vector<int> v;
        for(int j = 0 ; j < n ; j++)
            v.push_back(i+j);

        arr.push_back(v);

    }
print4(arr);

return 0;

}

//C++ style vector of vectors version of print function

void print4(vector<vector<int>> &arr)
{
    for(int i = 0; i < arr.size() ; i++)
    {
        for(int j = 0; j < arr[i].size() ;j++ )
        {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}