#include<stdio.h>
#include<stdlib.h>
 
#define MAX 10000
 
#define initial 1
#define waiting 2
#define visited 3
 
int n;    
int adj[MAX][MAX];
int state[MAX]; 
void create_graph(int m,int s);
void BF_Traversal(int k,int s,int n);
void BFS(int v,int s,int n);
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

struct list
{
	int data;
	int colour;
	struct list *next;
};

typedef struct list node;

node* array[vertices+1];
int main()
{
	int m,s,k;
	scanf("%d",&n);
	scanf("%d",&s);
	scanf("%d",&k);
    create_graph(n,s);
    BF_Traversal(k,s,n);
    return 0;
}
 
void BF_Traversal(int k,int s,int n)
{
    int v;
    
    for(v=0; v<n; v++) 
        state[v] = initial;
    
    //printf("Enter Start Vertex for BFS: \n");
    while(k--){
    	for(v=0; v<n; v++) 
        state[v] = initial;
    scanf("%d", &v);
    BFS(v,s,n);
}
}
 
void BFS(int v,int s,int n)
{
    int i;
    int h[v];
    insert_queue(v);
    state[v] = waiting;
    int j=0;
    int q=0;
    while(!isEmpty_queue())
    {
        v = delete_queue( );
        state[v] = visited;
        //printf("%d\n",v );
        //printf("%d\n",s );
    //rintf("%d\n",h[j] );
        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial) 
            {
                insert_queue(i);
                state[i] = waiting;
            }
                  if (q<v)
        	q=v;  
        }
        if(v>n)
        {
        	printf("\n");
        	return;
        }

        j++;
        //printf("%d\n",q );

    }
        if(s==0)
        	q=0;
    printf("%d\n",q );
    
}
 
void insert_queue(int vertex)
{
    if(rear!=MAX-1)
    {
        if(front == -1) 
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}
 
int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}
 
int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        //printf("Queue Underflow\n");
        printf("\n");
        exit(1);
    }
    
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}
 
void create_graph(int m,int s)
{
    int count,max_edge,origin,destin;
 
    //printf("Enter number of vertices : ");
    //scanf("%d",&n);
    //printf("%d\n",m );
    n=m;
    max_edge = n*(n-1);
 	//printf("%d\n",n );
    while(s--)
    {
        //printf("Enter edge %d( -1 -1 to quit ) : ",count);
        scanf("%d %d",&origin,&destin);
 
        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            //printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}