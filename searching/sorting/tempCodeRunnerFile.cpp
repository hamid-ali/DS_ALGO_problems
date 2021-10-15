
    public:
    
    int custum_search(int arr[] , int  low , int high , int  key)
    {
        int mid = low + (high - low)/2 , res = 0;
        int l = low , h = high ;
        while(l <= h)
        {
            mid = l + (h - l)/2 ;

            if(arr[mid] >= key )
            {
                if(mid == low) return res;

                else if(arr[mid-1] < key) return mid-1;