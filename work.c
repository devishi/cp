#include <stdio.h>
#include <string.h>

int main()
{
	int q,k,i;
	long long int l,r;
	scanf("%d",&q);
	while(q--)
	{
		long long int max,le,ri,no,j,k,t;
		scanf("%lld %lld %lld",&l,&r,&k);
		if(k==1)
			printf("%lld\n",r-l+1);
		else
		{
			max=0;
			for(j=l;j<=r;j++)
			{
				ri=0;
				while(l>=1)
				{
					no=l%10;
					if(l%no==0)
						ri++;
					l/=10;
				}
				if(ri>=k)
					max++;
			}
			printf("%lld\n",max );
		}
	}
	return 0;
}