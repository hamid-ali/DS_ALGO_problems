int table[256] ;

void initialize()
{
    table[0] = 0 ;
    for(int i = 1 ; i < 256 ; i++)
    {
        table[i] = (i & 1) + table[i/2] ;
    }
}

int countSetbits2(int n)
{
    int res = 0 ;

   
        res += table[n & 0xff] ;
        
        n = n>>8;

        res += table[n & 0xff] ;
        
        n = n>>8;

        res += table[n & 0xff] ;
        
        n = n>>8;

       res += table[n & 0xff] ;
    
    

    return res;
}