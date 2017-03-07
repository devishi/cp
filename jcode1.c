#include <stdio.h>
#include <stdlib.h>
void countSort(int a[], int n)
{
	if(n <= 0)
	    return;
	    
	int i;
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
	    a[i] = result[i];
	
}
int search(int arr[], int n, int x)
{
    int i;
    if(n <= 0)
	    return -2;
    for (i=n-1; i>=0; i--)
        if (arr[i] == x)
         return i;
    return -2;
}
int main()
{
	int i,j,l=0,k=100001,n;
	scanf("%d",&n);
	int arr[n+5],ar[n+5];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(search(arr,i,arr[i])!=-2)
		{
			j=abs(i-search(arr,i,arr[i]));
			ar[l]=j;
			l++;
		}
		countSort(ar,l);
	}
	if(l==0)
		printf("-1\n" );
	else
		printf("%d\n",ar[0] );
	return 0;
}