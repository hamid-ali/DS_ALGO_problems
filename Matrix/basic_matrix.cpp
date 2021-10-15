/* Important points:-
1. Elements are stored in row major order:
mat - 10    20      30      40      50      60
     2000  2004    2008   2012    2016    2020

int mat[2, 3]={ {10 , 20}
            {30 , 40}
            {50 , 60} }

2. Internal Curly brackets are optional
    so, int mat = {10, 20 , 30 , 40 , 50 , 60 }  is same above one.

3. Only 1st dimension can be omiited when we initialize:-
    int arr[][2] ={ { 1, 0}
                    {0 , 1} }
    
    int arr[][2][2] = { { {1 , 2}, {3 , 4} }
                        { {4 ,5 } , {6 , 7} } }

*/

// #include<iostream>

// using namespace std;

// int main()
// {
//     int m = 3 , n = 2;

//     int arr[][n] ={0 , 0 ,  0 , 0 ,  0 ,0 } ;  //from c14 C++ allows var to be used as array declaration.

//     for(int i = 0 ; i < m ; i++)
//     {
//         for(int j = 0 ; j < n ; j++)
//         {
//             arr[i][j] = i+j ;

//         }
//     }

//     for(int i = 0 ; i < m ; i++)
//     {
//         for(int j = 0 ; j < n ; j++)
//         {
//             cout<<arr[i][j] << "  ";
//         }
//         cout<<endl;
//     }

// }


//Other ways to create 

// 1. Double pointer

// #include<iostream>

// using namespace std;

// int main()
// {
//     int m = 3 , n = 2 ;
//     int **arr;
//      arr = new int *[m] ; //this will create an array of pointers dynamically in heap but if 
//                            //we wanted to use Stack then simply do int *arr[m] ;     

//     for(int i = 0; i< m ; i++)
//     {
//         arr[i] = new int[n] ; // this is dynamically allocated in Heap
//     }

//     for(int i = 0 ; i< m ; i++)
//     {
//         for(int j = 0 ; j < n ; j++)
//         {
//             arr[i][j] = 10 ;

//         }
//     }

//     for(int i = 0; i< m ;i++)
//     {
//         for(int j = 0 ; j < n ; j++ )
//         {
//             cout<<arr[i][j]<<"  ";
//         }
//         cout<<endl;
//     }

//     return 0;

// }


/*
3. Array of Vectors:-
-> Not as cache friendlly as simple 2-D aarys
-> Individual rows are of dynamic size
-> Easy to pass to afunction

To make it more robust/ dynamic we can even use vector of vectors which will make no of rows to also 
change dynamically rest will remai same as above.

vector< vector <int>> arr;


*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m = 3 , n= 2;

    // vector<int> arr[m] ;

    // for(int i = 0 ; i< m ; i++)
    // {
    //     for(int j = 0 ; j < n ; j++)
    //     {
    //         arr[i].push_back(10);

    //     }
    // } 

    vector< vector <int>> arr;          //vector of vectors to meke rows and columns both dynamic

    for(int i = 0 ; i < m ; i++ )
    {   
        vector<int> v;
        for(int j = 0 ; j < n ; j++)
            v.push_back(i+j);

        arr.push_back(v);

    }



    for(int i = 0; i< m ; i++)
    {
        for(int j = 0 ; j < n; j++)

            cout<<arr[i][j]<<" ";

        cout<<endl;
    }

    return 0 ;

}