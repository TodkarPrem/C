#include<stdio.h>
int my_htoi(char *);

int main()
{
	char str[30];
	int res;
	printf("Enter hex no(str): ");
	scanf("%s",str);

	res=my_htoi(str);
	printf("Converted int value: %d\n",res);
}

int my_htoi(char *ptr)
{
	int i,j,res=0,mul=1;
	if(ptr[0]=='0')
		j=2;
	else
		j=0;

	for(i=0; ptr[i]; i++);

	for(--i; i>=j; i--)
	{
		if(ptr[i]>='0' && ptr[i]<='9')
			res=res + mul * (ptr[i]-48);
		else if(ptr[i]>='a' && ptr[i]<='f')
			res=res + mul * (ptr[i]-87);
		else if(ptr[i]>='A' && ptr[i]<='F')
			res=res + mul * (ptr[i]-55);
		else
			break;
		mul=mul*16;
	}
	return res;
}
