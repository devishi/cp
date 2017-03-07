#include <stdio.h>
#include <string.h>
int main()
{
	int w;
    printf("1\n3 1 1 2\n3 4 4 5\n");
    fflush(stdout);
    scanf("%d",&w);
    if(w==0)
    	printf("2\n3\n");
    else if(w==1)
    	printf("2\n2\n");
    else if(w==2)
    	printf("2\n1\n");
    else if(w==-1)
    	printf("2\n5\n");
    else if(w==-2)
    	printf("2\n4\n");
    return 0;
}