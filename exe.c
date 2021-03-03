#include<stdio.h>
#include<conio.h>
int main()
{
    char c;
	int l,d,s,o;
	l=d=s=o=0;
	do
	{
		c=getchar();
		if('0'<=c&&'9'>c) d=d+1;
		else
		{
			if(c>='A'&&c<='z') l=l+1;
			else
			{
				if(c==' ')s=s+1;
				else o=o+1;
			}
		}
	}
	while(c!='\n');
	printf("letter=%d\n digit=%d\n spase=%d\n other=%d\n",1,d,s,o);
	return 0;
}