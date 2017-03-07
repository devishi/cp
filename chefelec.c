#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int find(char arr[],long long int n,long long int cord[])
{
	long long int i=0,j,a=0,b=n-1,k;
	long long int dist=0,m=0;
	if(arr[0]=='0')
	{
		while(i<n)
		{
			if(arr[i]=='1')
			{
				dist+=cord[i]-cord[0];
				a=i;
				break;
			}
			i++;
		}
	}
	i=n-1;
	if(arr[i]=='0')
	{
		while(i>=0)
		{
			if(arr[i]=='1')
			{
				dist+=cord[n-1]-cord[i];
				b=i;
				break;
			}
			i--;
		}
	}
	i=a;
	while(i<=b)
	{
		if(arr[i]=='1')
		{
			a=i;
		}
		else
		{
			k=-1;
			for(j=i;j<n;j++)
			{
				if(arr[j]=='1')
				{
					k=j;
					break;
				}
			}
			m=0;
			for(j=a+1;j<=k;j++)
			{
				dist+=cord[j]-cord[j-1];
				if(m<cord[j]-cord[j-1])
					m=cord[j]-cord[j-1];
			}
			i=k;
			a=k;
			dist-=m;
		}
		i++;
	}
	return dist;
}
			
long long int main()
{
	long long int t,n,i,j,k;
	scanf("%lld",&t);
	while(t--)
	{
		long long int dist=0;
		scanf("%lld",&n);
		char arr[n+5];
		long long int cord[n+5];
		scanf("%s",arr);
		for(i=0;i<n;i++)
			scanf("%lld",&cord[i]);
		if(strlen(arr)==1)
			printf("0\n");
		else
		{
			dist=find(arr,n,cord);
			printf("%lld\n",dist );
		}
	}
	return 0;
}