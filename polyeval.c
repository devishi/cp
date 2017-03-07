#include <stdio.h>
#include <stdlib.h>

long long int horner(long long int poly[],long long int n,long long int x)
{
	long long int i;
    long long int result = poly[n-1]; 
    for (i=1; i<n; i++)
        result = ((result*x )%786433+ poly[n-i-1])%786433;
    return result;
}

long long int main()
{
  	long long int n,i,x,v=1,j;
   	long long int ans;
   	scanf("%lld",&n);
   	long long int arr[n+3];
   	for(i=0;i<n+1;i++)
   	{
   		scanf("%lld",&arr[i]);
   	}
   	long long int q;
   	scanf("%lld",&q);
   	for(i=0;i<q;i++)
   	{
   		ans=0;
   		scanf("%lld",&x);
   		ans=horner(arr,n+1,x);
   		printf("%lld\n",ans);
   	}
   	return 0;
} 


     
    