#include <stdio.h>
#include <stdlib.h>
int search(long long int c[],long long int d[],long long int l,long long int a[],int n,long long int search,int k)
{
	int i,t,j;
	long long int s;
	if (n==0)
		s=0;
	else
		s=a[n-1];
 	for(s;s<a[n];s++)
 	{
 		//printf("%lld\n",s );
 		long long int sum=0;
		for(j=0;j<k;j++)
		{

			if(c[j]+d[j]*s>=l)
			{

				sum+=c[j]+d[j]*s;
			}
		}
		if(sum>=search)
			return s;
	}
}

int binarySearch(long long int c[],long long int d[],long long int l,long long int arr[],)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
    if (arr[m] == x) 
        return m;  
    if (arr[m] < x) 
        l = m + 1; 
    else 
         r = m - 1; 
  }
  return -1; 
}
void countSort(long long int a[], int n)
{
	if(n <= 0)
	    return;
	    
	int i;
	int max = -10000;
	
	for(i = 0; i < n ; i++)
	    if(a[i] > max)
	        max = a[i];
	
	long long int count[max+1];
	for(i = 0 ; i <= max; i++)
	    count[i] = 0;
	
	for(i = 0; i < n; i++)
	{
	    long long int ele = a[i];
	    count[ele] = count[ele] + 1;
	}
	
	for(i = 1 ; i <= max; i++)
	    count[i] = count[i] + count[i-1];
	
	long long int result[n];
	
	for(i = 0; i < n ; i++)
	{
	    long long int ele = a[i];
	    long long int loc = count[ele] - 1;
	    result[loc] = ele;
	    count[ele] = count[ele] - 1;
	}
	
	for(i =0; i < n; i++)
	    a[i] = result[i];
	
}

int main()
{
	int i,n,j;
	long long int m;
	scanf("%d",&n);
	long long int l,w;
	scanf("%lld",&w);
	scanf("%lld",&l);
	long long int h[2][100005],a[100005];
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&h[0][i],&h[1][i]);
		if(h[0][i]>=l){a[i]=0;}
		else if (h[1][i]==0)
			a[i]=(l-h[0][i]);

		else
			a[i]=(l-h[0][i])/h[1][i];
	}
	countSort(a,n);
	binarySearch(h[0],h[1],l,a,w,n);
	m=search(h[0],h[1],l,a,i,w,n);
	printf("%lld\n",m);
	return 0;
}