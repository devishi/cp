#include <stdio.h>
#include <stdlib.h>
int compare(int arr1[],int arr2[],int arr3[], int n1,int n2,int n3, int sum1,int sum2,int sum3)
{
	int ans=0;
	while(sum1!=sum2 || sum2!=sum3)
	{
		if(sum1<=0 || sum2<=0 || sum3<=0)
		{
			sum1=0;
			break;
		}	
		if(sum1>=sum2 && sum1>=sum3 && sum2>=0 && sum3>=0)
		{
			sum1-=arr1[n1-1];
			n1--;
		}
		else if(sum2>=sum1 && sum2>=sum3 && sum1>=0 && sum3>=0)
		{
			sum2-=arr2[n2-1];
			n2--;
		}
		else if(sum3>=sum2 && sum3>=sum1 && sum1>=0 && sum2>=0)
		{
			sum3-=arr3[n3-1];
			n3--;
		}
	}
	ans=sum1;
	return ans;
}
int main()
{
	int j,n1,n2,n3,i,sum1=0,sum2=0,sum3=0;
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);
	int arr1[n1+2],arr2[n2+2],arr3[n3+3];
	for(i=0;i<n1;i++)
	{
		scanf("%d",&arr1[n1-1-i]);
		sum1+=arr1[n1-1-i];
	}
	for(i=0;i<n2;i++)
	{
		scanf("%d",&arr2[n2-1-i]);
		sum2+=arr2[n2-1-i];
	}
	for(i=0;i<n3;i++)
	{
		scanf("%d",&arr3[n3-1-i]);
		sum3+=arr3[n3-1-i];
	}
	j=compare(arr1,arr2,arr3,n1,n2,n3,sum1,sum2,sum3);
	printf("%d\n",j );
	return 0;
}