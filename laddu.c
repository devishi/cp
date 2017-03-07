#include <stdio.h>
#include <string.h> 
int main()
{
	int t,b,a,sum,flag=0;
	char ask1[25],ask2[25];
	scanf("%d",&t);
	while (t--)
	{
		sum=0;
		flag=0;
		scanf("%d",&a);
		scanf("%s",ask1);
		if(strcmp(ask1,"INDIAN")==0)
			flag=1;
		while(a--)
		{
			scanf("%s",ask2);
			if(strcmp(ask2,"CONTEST_WON")==0)
			{
				scanf("%d",&b);
				if(b<=20)
					sum+=300+20-b;
				else
					sum+=300;
			}
			else if(strcmp(ask2,"TOP_CONTRIBUTOR")==0)
			{
				sum+=300;
			}
			else if(strcmp(ask2,"BUG_FOUND")==0)
			{
				scanf("%d",&b);
				sum+=b;
			}
			else if(strcmp(ask2,"CONTEST_HOSTED")==0)
			{
				sum+=50;
			}
		}
		if(flag==1)
			printf("%d\n",sum/200 );
		else
			printf("%d\n",sum/400 );
	}
	return 0;
}