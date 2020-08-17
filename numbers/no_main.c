#include<stdio.h> 
#include<stdlib.h> 

/*
#define fun m##a##i##n
int fun()
{
    printf("Geeksforgeeks");
    return 0;
}
*/

// entry point function 
int nomain() 
{ 
    puts("Geeksforgeeks"); 
    return 0; 
}   
  
void _start()
{  
    // calling entry point 
    nomain();  
    exit(0); 
} 
