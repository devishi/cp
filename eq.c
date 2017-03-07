#include <stdio.h>
#include <stdlib.h>

int countSort(int arr[],int l,int r,int u)
{
	int a[r-l+1],i,k;
	int n=r-l;
	for (i = l-1; i < r-1; ++i)
	{
		a[i-l+1]=arr[i];
	}
	if(n <= 0)
	    return -1;
	int max = -10000;
	
	for(i = 0; i < n ; i++)
	    if(a[i] > max)
	        max = a[i];
	
	int count[max+1];
	for(i = 0 ; i <= max; i++)
	    count[i] = 0;
	
	for(i = 0; i < n; i++)
	{
	    int ele = a[i];
	    count[ele] = count[ele] + 1;
	}
	
	for(i = 1 ; i <= max; i++)
	    count[i] = count[i] + count[i-1];
	
	int result[n];
	
	for(i = 0; i < n ; i++)
	{
	    int ele = a[i];
	    int loc = count[ele] - 1;
	    result[loc] = ele;
	    count[ele] = count[ele] - 1;
	}
	
	for(i =0; i < n; i++)
	{
	    a[i] = result[i];
	}
	k=a[u-1];
	if(k>n)
		return -1;
	else
	{	
		return k;
	}
}

int main()
{
	int N,Q,i,k,flag,temp;
	int l,r;
	scanf("%d",&N);
	scanf("%d",&Q);
	int arr[N],b[Q][5];
	for (i = 0; i < N; ++i)
	{
		scanf("%d",&arr[i]);
	}
	for ( i = 0; i < Q; ++i)
	{
		scanf("%d",&b[i][0]);
		scanf("%d",&b[i][1]);
		scanf("%d",&b[i][2]);
		scanf("%d",&b[i][3]);
		scanf("%d",&b[i][4]);
	}
	for (i = 0; i < Q; ++i)
	{
		if(k<=0)
			k=0;
		flag=0;
		l=((b[i][0]*k)+b[i][1])%N +1;
		r=((b[i][2]*k)+b[i][3])%N +1;

		if(l>r)
		{
			temp=l;
			l=r;
			r=temp;
		}
		if(l!=r && l>=0 && r>=0 && l<=N && r<=N)
		{
			k=countSort(arr,l,r,b[i][4]);
			flag=1;
		}
		if(flag==1)
			printf("%d\n",k );
		else
		{
			k=-1;
			printf("-1\n");
		}
	}
	return 0;
}