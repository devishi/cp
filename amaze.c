#include <stdio.h>
#include <stdlib.h>

struct set
{
    int object;
};

int amazingness(int a[],int V)
{
	int v,i,j;
    int ans = 0;
    struct set *sets =(struct set*) malloc( V * sizeof(struct set) );
    for ( i = 0; i < a.length(); i++ ) 
    {
         int val = 0;
         for ( j = i; j < a.length(); j++ ) 
         {
            val ^= a[j];  
            if (val not present in set s before) 
            {
                ans += val;
                Union()
            }
         }
   }
   return ans;
}
int main()
{
	int v,V;
	

}