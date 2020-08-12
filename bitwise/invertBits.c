#include<stdio.h>
int invert(int,int,int);
int main()
{
	int x,n,p,i;
	printf("Enter x: ");
	scanf("%d",&x);

	printf("Enter total bits to invert: ");
	scanf("%d",&n);

	printf("Enter starting bit: ");
	scanf("%d",&p);

	printf("Binary format before inverting x:  ");
	for(i=31; i>=0; printf("%d",x>>i&1), i--);
	printf("\n");

	x=invert(x,p,n);

	printf("Binary format after  inverting x:  ");
	for(i=31; i>=0; printf("%d",x>>i&1), i--);
	printf("\n");
}


int invert(int n,int start, int tot)
{
	int tmp;
	for(tmp=start; start<tot+tmp; start++) {
		n=n^1 << start;
	}

	return n;	//(n >> (start+1-tot)) ^ ~(0 << tot);
}		
