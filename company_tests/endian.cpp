int main()
{
	unsigned int n = 1 ;
	char *ptr ;
	ptr = (char*)&n ;

	if(*ptr)
		cout<<"Lttle Endian!"<<endl ;

	else
		cout<<"Big Endian! "<<endl ; 

return 0 ;

}