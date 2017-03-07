#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int binary(char hexaDecimal[])
{
	long int i=0,j=0;
	int b[strlen(hexaDecimal)*4+5];
	while(i<strlen(hexaDecimal))
    {
        switch(hexaDecimal[i])
        {
            case '0': b[j]=0;
            		b[j+1]=0;
            		b[j+2]=0;
            		b[j+3]=0; break;
            case '1': b[j]=0;
            		b[j+1]=0;
            		b[j+2]=0;
            		b[j+3]=1; break;
            case '2': b[j]=0;
            		b[j+1]=0;
            		b[j+2]=1;
            		b[j+3]=0; break;
            case '3': b[j]=0;
            		b[j+1]=0;
            		b[j+2]=1;
            		b[j+3]=1; break;
            case '4': b[j]=0;
            		b[j+1]=1;
            		b[j+2]=0;
            		b[j+3]=0; break;
            case '5': b[j]=0;
            		b[j+1]=1;
            		b[j+2]=0;
            		b[j+3]=1; break;
            case '6': b[j]=0;
            		b[j+1]=1;
            		b[j+2]=1;
            		b[j+3]=0; break;
            case '7': b[j]=0;
            		b[j+1]=1;
            		b[j+2]=1;
            		b[j+3]=1; break;
            case '8': b[j]=1;
            		b[j+1]=0;
            		b[j+2]=0;
            		b[j+3]=0; break;
            case '9': b[j]=1;
            		b[j+1]=0;
            		b[j+2]=0;
            		b[j+3]=1; break;
            case 'A': b[j]=1;
            		b[j+1]=0;
            		b[j+2]=1;
            		b[j+3]=0; break;
            case 'B': b[j]=1;
            		b[j+1]=0;
            		b[j+2]=1;
            		b[j+3]=1; break;
            case 'C': b[j]=1;
            		b[j+1]=1;
            		b[j+2]=0;
            		b[j+3]=0; break;
            case 'D': b[j]=1;
            		b[j+1]=1;
            		b[j+2]=0;
            		b[j+3]=1; break;
            case 'E': b[j]=1;
            		b[j+1]=1;
            		b[j+2]=1;
            		b[j+3]=0; break;
            case 'F': b[j]=1;
            		b[j+1]=1;
            		b[j+2]=1;
            		b[j+3]=1; break;
            return 0;
        }
        i++;
        j+=4;
    }
    return b;
}
int bin(long long int binaryval)
{
	int remainder,hexadecimalval,i=1;
	while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    return hexadecimalval;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,m,j[100001],k[100001],l[100001],tr=0,ans=-1;
		char a[100001],b[100001],c[100001];
		scanf("%d",&i);
		scanf("%s",a);
		scanf("%s",b);
		scanf("%s",c);
		*j=binary(a);
		*k=binary(b);
		*l=binary(c);	
		while(l[m])
		{
			if(l[m]==0)
			{
				if(j[m]==1 || k[m]==1)
				{
					if(j[m]!=k[m] && j[m]==1)
					{
						j[m]=0;
					}
					else if(j[m]!=k[m] && k[m]==1)
						k[m]=0;
					else
					{
						k[m]=0;
						j[m]=0;
						tr++;
					}
					tr++;
				}
			}
			else if(l[m]==1)
			{
				if((j[m]==0 && k[m]==0))
				{
					k[m]=1;
					tr++;
				}
			}
			m++;
		}
		m=0;
		while(tr<i && j[m] && k[m])
		{
			if(j[m]==1 && k[m]!=0){
				tr++;
				j[m]=0;
			}
			else if((i-tr)%2==0 && j[m]==1 && k[m]==0)
			{
				j[m]=0;
				k[m]=1;
				tr+=2;
			}
		}
		if(tr<=i)
		{
			printf("%d\n",bin(j) );
			printf("%d\n",bin(k) );
		}
		else
			printf("-1\n");
	}
	return 0;
}