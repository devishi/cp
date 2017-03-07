#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	long long int k,j,n,c=0;
	while(t--)
	{
		scanf("%lld",&n);
		int a;
		int str[40];
		c=0;
		float f=n;
		if(n==1)
		{
			printf("0\n");
			continue;
		}

		//printf("%lld\n",f );
		while(n>1)
		{
			if(n%5==0){
				n--;
				a=8;
			}
			else
				a=(n%5-1)*2;
			n=n/5;
			str[c]=a;
			c++;
			n++;
			// if(a==0)
			// {
			// 	--n;
			// }
			// switch(ai)
			// {
			// 	case 0:str[c]=4;
			// 	break;
			// 	case 1:str[c]=3;
			// 	break;
			// }
			// ++c;
		}
		for(k=c-1;k>=0;k--)
		{
			printf("%d",str[k] );
		}
		printf("\n");
		// if(n%5!=0)
		// 	b=(n-n%5)*4;
		// else
		// 	b=(n-5)*4;
		// if(n%5!=0)
		// 	printf("%lld\n",b+a );
		// else
		// 	printf("%lld\n",b+8 );
	}
	return 0;
}