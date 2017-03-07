#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i=0,j,k=0,b,n,t;
	scanf("%d",&t);
	while(t--)
	{
		float sum=0;
		k=0;
		i=0;
		scanf("%d",&n);
		b=n;
		while(b--)
		{
			scanf("%d",&j);
			if(j==2)
			{
				k=2;
			}
			else if(j==5)
			{
				i=1;
			}
			sum+=j;
		}
		sum=sum/n;
		if(k==2 || i!=1 || (i==1 && sum<4.0))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}