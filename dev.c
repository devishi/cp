#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N,q,i,min,max;
	scanf("%d",&N);
	scanf("%d",&q);
	int arr[N+2],t;
	for(i=0;i<N;i++)
	{
		if(i==0)
		{
			scanf("%d",&arr[i]);
			min=arr[i];
			max=arr[i];
		}
		else
			scanf("%d",&arr[i]);
		if(arr[i]>max)
			max=arr[i];
		if(arr[i]<min)
			min=arr[i];
	}
	while(q--)
	{
		scanf("%d",&t);
		if(t>=min && t<=max)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}