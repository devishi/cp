#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long factorial(int n,int k)
{
    long long ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(j=1;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}
int main()
{
	int t,n,k,i,b=0;
	long int mod=1000000007;
	scanf("%d",&t);
	long long int q,r,d,s;
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		long long int a[100005];
		b=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]==0)
				b++;
		}
		if(n-b<k)
			k=n;
		d=factorial(n-b,k);
		if(k%2==0)
		{
			printf("%lld\n",(d+1)%mod );
		}
		else
			printf("%lld\n",d%mod );
	}
}