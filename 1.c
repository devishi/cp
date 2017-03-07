#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,l;
    long long int sum=0;
    char a[1000005];
    scanf("%s",a);
    if(strlen(a)<4)
    	sum=0;
    else{
    for(i=0;i<strlen(a)-3;i++)
    {
        for(j=i+3;j<strlen(a);j++)
            if(a[i]==a[j])
            {
                for(k=i+1;k<j-1;k++)
                    for(l=k+1;l<j;l++)
                        if(a[k]==a[l])
                        {
                            sum++; 
                            sum %=1000000007 ;                       
                        }
            }

    }
	}
    printf("%lld\n",sum %1000000007);
    return 0;
}