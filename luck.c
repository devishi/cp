#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int t,m;
	scanf("%d",&t);
	while(t--)
	{
		int q=0,c=0,flag1=0,flag2=0,d=0;
		char a[1000001],b[1000001];
		scanf("%s",a);
		scanf("%s",b);
		for(q=0;q<strlen(a);q++)
		{
			if(a[q]=='0')
			{
				flag1=1;
			}
			else if(a[q]=='1')
			{
				flag2=1;
			}
			if(a[q]-b[q]==-1)
				d++;
			if(a[q]-b[q]==1)
				c++;
		}

		if(flag1==1 && flag2==1)
		{
			printf("Lucky Chef\n");
			if(d>c)
				printf("%d\n",d);
			else
				printf("%d\n",c);
		}
		else
			printf("Unlucky Chef\n");
	}
	return 0;
}