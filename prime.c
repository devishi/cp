#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int divisor(int n)
{
  int i=1,t=1,flag=0;
  while(i <= sqrt(n))
  {
      if(n%i==0) 
      {
        t++; 
        if (i == (n / i)) 
        {
          flag=1;
          t--;
        }
      } 
    i++;
  }
  if (flag==0)
    return t*2;
  else 
    return (t*2)-1;
}


int main()
{
  int t,n,q,m=1;
  scanf("%d",&t);
  while(t--)
  {
    int flag=0;
    scanf("%d",&n);

    if(n%6!=0)
    {
      printf("Chef\n");
    }
    else
      printf("Misha\n");
  }
  return 0;
}