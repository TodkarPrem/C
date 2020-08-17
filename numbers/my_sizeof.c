#include<stdio.h> 
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type) 

int main() 
{ 
	char w;
	int x;
	float y;
	double z;

    	printf("%ld %ld %ld %ld\n", my_sizeof(w), my_sizeof(x), my_sizeof(y), my_sizeof(z));
	return 0; 
} 

