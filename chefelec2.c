#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int t,n,i,j,a=-1,b=0,k;
	scanf("%d",&t);
	while(t--)
	{
		long long int dist=0,d1,d2;
		scanf("%d",&n);
		char arr[n+5];
		scanf("%s",arr);
		if(n==1)
		{   
			scanf("%lld",&d1);
			printf("0\n");
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(arr[i]==arr[i+1] && arr[i]=='1')
				{
					scanf("%lld",&d1);
					d2=d1;
					a=i;
				}
				else if (arr[i]=='1')
				{
					scanf("%lld",&d2);
					a=i;
					dist+=cord[i+1]-cord[i];
				}
				else if(arr[i]=='0' && arr[i+1]=='1')
				{
					scanf("%lld",&d1);
					if(a!=-1)
					{
						if(cord[i]-cord[a]>cord[i+1]-cord[a+1])
						{
							dist+=cord[i+1]-cord[a+1];
							dist-=cord[i]-cord[a];
							a=i+1;
						}
						else
							a=i+1;
					}
					else
						dist+=cord[i+1]-cord[i];
				}
				else
					dist+=cord[i+1]-cord[i];
				scanf("%lld",&cord[i]);
			}
		}
	}
	return 0;
}