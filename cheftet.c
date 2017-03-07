#include <stdio.h>
#include <stdlib.h>

long long int find(long long int x,long long int d,long long int b[],long long int i)
{
	if(b[i-1]+d==x)
	{
		b[i-1]=0;
		return 1;
	}
	else if(b[i+1]+d==x)
	{
		b[i+1]=0;
		return 1;
	}
	else if(b[i]+d==x)
	{
		b[i]=0;
		return 1;
	}
	else if(b[i-1]+b[i]+d==x)
	{
		b[i-1]=0;
		b[i]=0;
		return 1;
	}
	else if(b[i]+b[i+1]+d==x)
	{
		b[i]=0;
		b[i+1]=0;
		return 1;
	}
	else if(b[i-1]+b[i+1]+d+b[i]==x)
	{
		b[i-1]=0;
		b[i+1]=0;
		b[i]=0;
		return 1;
	}
	else if(b[i-1]+d+b[i+1]==x)
	{
		b[i-1]=0;
		b[i+1]=0;
		return 1;
	}
	else if(d==x)
	{
		return 1;
	}
	else 
		return 0;
}


long long int fumax(long long int tr[],long long int p)
{
	if(p==0)
		return -1;
	long long int max=tr[0];
	if(p==1)
		return tr[0];
	else
	{
		while(p--)
			if(tr[p]>max)
				max=tr[p];
		return max;
	}
}
int main()
{
	long long int t,i,j;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,k,flag=0,max=1;
		scanf("%lld",&n);
		long long int a[n+1],b[n+1],ans[4],tr[4];
		for(i=0;i<n;i++)
			scanf("%lld",&b[i]);
		a[n]=0;
		b[n]=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		if(n==1)
			printf("%lld\n",a[0]+b[0]);
		else
		{
			long long int p=0;
			ans[0]=a[0]+b[0];
			ans[1]=a[0]+b[1];
			ans[2]=a[0]+b[0]+b[1];
			ans[3]=a[0];
			for(i=0;i<4;i++)
			{
				long long int fi[n+1];
				for(k=0;k<n+1;k++)
				{
					fi[k]=b[k];
				}
				if(i==0)
					fi[0]=0;
				else if(i==1)
					fi[1]=0;
				else if(i==2)
				{
					fi[0]=0;
					fi[1]=0;
				}
				max=1;
				for(j=1;j<n;j++)
				{
					if(find(ans[i],a[j],fi,j)==0)
					{
						max=0;
						break;
					}
				}
				if(max!=0)
				{
					tr[p]=ans[i];
					p++;
				}
			}
			max=fumax(tr,p);
			if(p!=0)
				printf("%lld\n",max);
			else
				printf("-1\n");
		}
	}
	return 0;
}