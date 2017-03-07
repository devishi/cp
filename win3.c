#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dest;
};
 
struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    return graph;
}
 
struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int main()
{
	int n,m,a,b;
	scanf("%d",&n);
	scanf("%d",&m);
    struct Graph* graph = createGraph(n, m);
    while(m--)
	{
		scanf("%d",&graph->edge[m].src-1);
    	scanf("%d",&graph->edge[m].dest-1);
	}
	struct subset *subsets =(struct subset*) malloc( V * sizeof(struct subset) );

    for (int v = 0; v < m; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < m - 1)
    {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
	if(m>=n-1)
		printf("-1\n");
	else
	{
		printf("%d\n",a);
		printf("%d\n",b );
	}
	return 0;
}