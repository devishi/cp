#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100001

typedef struct Q
{
    int data[MAX];
    int R,F;
}Q;

typedef struct node
{
    struct node *next;
    int vertex;
}node;

int n; 

void DFS(node **G,int *visited,int i)
{
    node *p;
    printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
        i=p->vertex;
        if(!visited[i])
            DFS(G,visited,i);
        p=p->next;
    }
}
int empty(Q *P)
{
    if(P->R==-1)
        return(1);
    return(0);
}

int full(Q *P)
{
    if(P->R==MAX-1)
        return(1);
    return(0);
}

void enqueue(Q *P,int x)
{
    if(P->R==-1)
    {
        P->R=P->F=0;
        P->data[P->R]=x;
    }
    else
    {
        P->R=P->R+1;
        P->data[P->R]=x;
    }
}

int dequeue(Q *P)
{
    int x;
    x=P->data[P->F];
    if(P->R==P->F)
    {
        P->R=-1;
        P->F=-1;
    }
    else
        P->F=P->F+1;
    return(x);
}

void insert(node **G,int vi,int vj)
{
    node *p,*q;
    q=(node *)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        p=G[vi];
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}                 
void readgraph(node **G,int *visited)
{     
	int i,vi,vj,no_of_edges;
    printf("\nEnter no. of vertices :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        G[i]=NULL;
    printf("\nEnter no of edges :");
    scanf("%d",&no_of_edges);
    for(i=0;i<no_of_edges;i++)
    {
    	printf("\nEnter an edge (u,v)  :");
        scanf("%d%d",&vi,&vj);
        insert(G,vi,vj);
        insert(G,vj,vi);
    }
}      

int main()
{
    int i,op,t;
    scanf("%d",&t);
    printf("elo ji%d\n", t);
    while(t--)
    { 
    	int visited[MAX];
		node *G[100001];                
      	readgraph(G,visited);
      	for(i=0;i<n;i++)
            visited[i]=0;
        scanf("%d",&i);
        DFS(G,visited,i);
    }
    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct queue{
// 	int x;
// 	struct queue *next;
// }queue;

// typedef struct listnode{
// 	int id;
// 	struct listnode *next;
// }listnode;

// typedef struct adjlist{
// 	listnode *head;
// }adjlist;

// typedef struct graph{
// 	int vertices;
// 	adjlist *array;
// }graph;
// void enqueue(queue **head , queue **tail , int n)
// {	
// 	if(*head==NULL)
// 	{	
// 		queue *temp=malloc(sizeof(queue));
// 		temp->x=n;
// 		temp->next=NULL;
// 		*head=temp;
// 		*tail=temp;
// 		return;
// 	}
// 	else
// 	{	
// 		queue *temp=malloc(sizeof(queue));
// 		temp->x=n;
// 		temp->next=NULL;
// 		(*tail)->next=temp;
// 		*tail=temp;
// 		return;
// 	}
// }

// int qempty(queue **head)
// {
// 	if(*head==NULL)
// 		return 0;
// 	return 1;
// }
// int dequeue(queue **head , queue **tail)
// {
// 	int t=(*head)->x;
// 	queue *temp=*head;
// 	(*head)=temp->next;
// 	free(temp);
// 	temp=NULL;
// 	return t;
// }
// listnode *newnode(int id)
// {
// 	listnode *node=malloc(sizeof(listnode));
// 	node->id=id;
// 	node->next=NULL;
// 	return node;
// }

// void creategraph(graph **g , int v)
// {
// 	*g=(graph *)malloc(sizeof(graph));
// 	(*g)->vertices=v;
// 	(*g)->array=(adjlist *)malloc(v*sizeof(adjlist));
// 	int i;
// 	for(i=0;i<v;++i)
// 		(*g)->array[i].head=NULL;
// }

// void addedge(graph **g , int u , int v)
// {	
// 	listnode *node=newnode(v);
// 	node->next=(*g)->array[u].head;
// 	(*g)->array[u].head=node;
// 	node=newnode(u);
// 	node->next=(*g)->array[v].head;
// 	(*g)->array[v].head=node;
// }

// int ans;

// void bfs(graph **g , int v , int *visited , int *level)
// {
// 	visited[v]=1;
// 	level[v]=0;

// 	queue *head=NULL,*tail=NULL;
// 	enqueue(&head,&tail,v);

// 	while(qempty(&head))
// 	{	
// 		int p=dequeue(&head,&tail);
// 		listnode *temp=(*g)->array[p].head;
// 		while(temp)
// 		{	
// 			if(!visited[temp->id])
// 			{	
// 				visited[temp->id]=1;
// 				level[temp->id]=level[p]+1;
// 				//ans+=1;
// 				enqueue(&head,&tail,temp->id);
// 			}
// 			temp=temp->next;
// 			//printf("%d\n",ans );
// 		}
// 	}
// }

// void DFS(graph **g,int i,int *visited)
// {
//     //queue *head=NULL;
//     //queue *tail=NULL;
//     //enqueue(&head,&tail,i);
//     visited[i]=1;
//     printf("%d\n",i );
// 	listnode *temp=(*g)->array[i].head;
// 	while(temp)
// 	{
//         if(!visited[temp->id])
//         {
// 			DFS(g,i,visited);	
// 			i++;		
//   		}
//   		temp=temp->next;
// 	}
// }
// int main()
// {	
// 	int t;
// 	int i, n, k, m, u, v;
// 	scanf("%d",&t);
// 	while(t--)
// 	{
// 		graph *g;

// 		v=0;
// 		ans=0;
// 		scanf("%d %d", &n, &m);
// 		creategraph(&g,n);


// 		for(i = 0; i < m; i++)
// 		{
// 			scanf("%d %d", &u, &v);
// 			addedge(&g,u-1,v-1);
// 		}
// 		int visited[g->vertices],j,level[g->vertices];
// 		for(j=0; j < g->vertices; j++)
// 		{
// 			visited[j]=0;
// 			level[j]=-1;
// 		}

// 		DFS(&g, 2, visited);

// 	}
// 	return 0;
// }
