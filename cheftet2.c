#include <stdio.h>

long long int fumax(long long int ans[],long long int p)
{
	long long int max=0;
	if(p==0)
		return -1;
	if(p==1)
		return ans[0];
	else
	{
		while(p--)
			if(ans[p]>max)
				max=ans[p];
		return max;
	}
}
long long int search(long long x,long long int d,long long int b[],long long int i)
{
	if(d==x)
		return 1;
	if(b[i-1]+d==x)
	{
		b[i-1]=0;
		return 1;
	}
	if(b[i]+b[i-1]+d==x)
	{
		b[i]=0;
		b[i-1]=0;
		return 1;
	}

	if(b[i-1]+b[i+1]+d==x)
	{
		b[i-1]=0;
		b[i+1]=0;
		return 1;
	}
	if(b[i]+d+b[i+1]+b[i-1]==x)
	{
		b[i]=0;
		b[i+1]=0;
		b[i-1]=0;
		return 1;
	}
	if(b[i]+d==x)
	{
		b[i]=0;
		return 1;
	}
	if(b[i]+b[i+1]+d==x)
	{
		b[i]=0;
		b[i+1]=0;
		return 1;
	}
	if(b[i+1]+d==x)
	{
		b[i+1]=0;
		return 1;
	}
	
	else
		return 0;
}

long long int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,i,j,flag;
		scanf("%lld",&n);
		long long int a[n+1],b[n+1],ans,find=0,max;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			find+=b[i];
		}
		a[n]=0;
		b[n]=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			find+=a[i];
		}
		find/=n;
		if(n==1)
			printf("%lld\n",a[0]+b[0] );
		else
		{
			long long int p=0;
			max=0;
			flag=1;
			for(j=1;j<n;j++)
			{
				if(search(find,a[j],b,j)==0)
				{
					flag=0;
					break;
				}
			}
			if(flag!=0)
				ans=find;
			if(flag!=0)
				printf("%lld\n",ans );
			else
				printf("-1\n");
		}
	}
	return 0;
}