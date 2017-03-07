#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int b=n,i,j,k,l,ans;
		long long int arr[n+5];
		while(b--)
		{
			scanf("%lld",&arr[b]);
		}
		if(n==1)
			printf("0\n");
		else{
			ans=0;
		for(i=0;i<n;i++)
			for(j=i;j<n;j++)
				for(k=j+1;k<n;k++)
					for(l=k;l<n;l++)
					{	
						if(arr[i]!=arr[k] && arr[i]!=arr[l] &&arr[j]!=arr[k] && arr[j]!=arr[l] )
						{
							ans++;
						}
					}
		cout << ans << "\n";
	}
	}
}