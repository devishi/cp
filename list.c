#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct subset
{
    int parent;
    long long int rank;
};
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void query(struct subset subsets[],int n)
{
    int xroot= find(subsets, n);
    printf("%lld\n",subsets[xroot].rank ); 
}
void Union(struct subset subsets[], int x, int y,int V)
{
    int xroot = find(subsets, x);
    long long int tx=0,v;
    int yroot = find(subsets, y);
    if(xroot==yroot)
        return;
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
        subsets[yroot].rank+=subsets[xroot].rank;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank+=subsets[yroot].rank;
    }
    else
    {
        if(xroot<yroot)
        {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank+=subsets[yroot].rank; 
        }
        else
        {
            subsets[xroot].parent = yroot;
            subsets[yroot].rank+=subsets[xroot].rank;
        }
    }
}
void max(struct subset subsets[],int V)
{
    long long int vmax=1;
    int v;
    for ( v = 1; v <= V; ++v)
    {
        int tr=find(subsets,v);
        if(subsets[tr].rank>vmax)
            vmax=subsets[tr].rank;
    }
    printf("%lld\n",vmax );
}
void min(struct subset subsets[],int V)
{
    int v;
    long long int vmin=subsets[1].rank;
    for ( v = 1; v <= V; ++v)
    {
        int tr=find(subsets,v);   
        if(subsets[tr].rank<vmin)
            vmin=subsets[tr].rank;
    }
    printf("%lld\n",vmin );
}

int main()
{
    int v,e,j;
    scanf("%d",&v);
    struct subset *subsets =(struct subset*) malloc( v * sizeof(struct subset) );
    for ( j = 1; j <= v; ++j)
    {
        subsets[j].parent = j;
        subsets[j].rank = 1;
    }
    scanf("%d",&e);
    char ch[10];
    while(e--)
    {
        scanf("%s",ch);
        int n,a;
        if(strcmp(ch,"Q")==0)
        {
            scanf("%d",&n);
            query(subsets,n);
        }
        if(strcmp(ch,"MAX")==0)
        {
            max(subsets,v);
        }
        if(strcmp(ch,"MIN")==0)
        {
            min(subsets,v);
        }
        if(strcmp(ch,"M")==0)
        {
            scanf("%d",&n);
            scanf("%d",&a);
            Union(subsets,n,a,v);
        }
    }
    return 0;
}
