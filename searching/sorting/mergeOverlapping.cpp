/*
i/p - { {5, 10} , {3, 15} , {18 , 30} , {2 , 7} }

o/p - {2, 15}, {18 , 30}


*/

struct interval
{
    int start , end ;
}

void mergeIntervals(Interval arr[] ,int n)
{
    sort(arr , arr+n ,myComp);

    int res = 0 ;

    for(int i = 1 ; i < n ; i++)
    {
        if( arr[res].end >= arr[i].st )
        {
            arr[res].end = max(arr[res].end , arr[i].end) ;
            arr[res].start = min(arr[res].start , arr[i].start )
        }

        else
        {
            res++; 
            arr[res] = arr[i] ;
        }
    }

    for(int i = 0 ; i <= res ; i++)
    {
        cout << arr[i].start <<" " <<arr[i].end <<endl ;
    }


}