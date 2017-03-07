#include <stdio.h>
#include <string.h>

char ch[1000000];
int a[26][1000000],b[26],mod=1000000007;
int main()
{
    scanf("%s",ch);
    int i,j,k,l;
    long long int sum1,sum2,sum3,sum=0,m,n1,n2,c;
    for(i=0;i<26;i++) 
        b[i]=0;
    for(i=0;i<strlen(ch);i++)
    {
        a[ch[i]-97][b[ch[i]-97]]=i;
        b[ch[i]-97]++;
    }
    for(i=0;i<26;i++) 
    {
        for(k=0;k<b[i];k++)
        {
            for(l=k+1;l<b[i];l++)
            {
                n1=a[i][k];
                n2=a[i][l];
                if(n2-n1==1) 
                    continue;
                for(j=0;j<26;j++)
                {
                    sum3=0;
                    for(m=0;((m<b[j])&&(b[j]>1));m++)
                    {
                        c=a[j][m];
                        if(c>n2) 
                            break;
                        if((c<n2)&&(c>n1)) 
                            sum3++;
                    }
                    sum+=(sum3*(sum3-1))/2;
                    sum%=mod;
                }
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}