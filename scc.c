#include<stdio.h>
#include<stdlib.h>
int a,b;
typedef struct Node
{
int val;
struct Node*next;
}node;

typedef struct Graph
{
int v;
node**arr;
node**arr2;
}graph;

typedef struct Stack
{
int data;
int capacity;
int*arr;
int count;
}stack;

stack*createstack(int capacity)
{
stack*s=(stack*)malloc(sizeof(stack));
s->capacity=capacity;
s->arr=(int*)malloc(sizeof(int)*capacity);
s->count=-1;
return s;	
}
	

graph*creategraph(int v)
{
int i;
graph*temp=(graph*)malloc(sizeof(graph));
temp->v=v;
for(i=1;i<v+1;i++)
temp->arr=(node**)malloc(sizeof(node*)*v);
for(i=1;i<v+1;i++)
temp->arr[i]=NULL;
return temp;
}

void addedge(graph*g,int u,int v)
{
node*temp=(node*)malloc(sizeof(node));
temp->val=v;
temp->next=g->arr[u];
g->arr[u]=temp;
}

node*createnode(int d)
{
node*temp=(node*)malloc(sizeof(node));
temp->val=d;
return temp;
}

void push(stack*s,int d)
{
	if(s->count==s->capacity)
	{
		//printf("stack is full");
		return;
	}
	s->count++;
	s->arr[s->count]=d;
	
}

int pop(stack*s)
{
int temp=s->arr[s->count];
s->count--;
return temp;
}

int Isempty(stack*s)
{
return(s->count==-1);
}

void fillorder(stack*s,graph*g,int v,int visited[])
{
	visited[v]=1;
	node*temp=g->arr[v];
	while(temp)
	{
		if(visited[temp->val]==0)
			fillorder(s,g,temp->val,visited);
		temp=temp->next;
		a+=1;
	}
	push(s,v);
}

graph*getreverse(graph*g)
{
	int i;
	g->arr2=(node**)malloc(sizeof(node*)*g->v);
	for(i=1;i<=g->v;i++)
		g->arr2[i]=NULL;

	node*temp;
	for(i=1;i<=g->v;i++)
	{
		temp=g->arr[i];
	while(temp)
	{
		node*n=createnode(i);
		n->next=g->arr2[temp->val];
		g->arr2[temp->val]=n;
		temp=temp->next;
	}
	}
	free(g->arr);
	return g;	
}

void dfsutil(graph*g,int v,int visited[])
{
visited[v]=1;
printf("%d",v);

node*temp=g->arr2[v];

while(temp)
{
	b+=1;
if(visited[temp->val]==0)
{
	dfsutil(g,temp->val,visited);
}
temp=temp->next;
}
}

void printscc(graph*g)
{
	//create a stack to hold g->v no of nodes
	stack*s=createstack(g->v);	
	
	int visited[g->v],i;
	for(i=1;i<=g->v;i++)
		visited[i]=0;
	
	for(i=1;i<=g->v;i++)
		if(visited[i]==0)
		{
			
			fillorder(s,g,i,visited);
		}
	graph*gr=getreverse(g);
	for(i=1;i<=g->v;i++)
		visited[i]=0;
	while(!Isempty(s))
	{
		int v=pop(s);
		if(visited[v]==0)
		{
			dfsutil(g,v,visited);
			printf(" ");
		}
	}
}

int main()
{
	int v,e,i,j;
	scanf("%d",&v);
	graph*g=creategraph(v);
	scanf("%d",&e);
	while(e--)
	{
		scanf("%d %d",&i,&j);
		addedge(g,i,j);
	}
printscc(g);
printf("\n%d\n",a );
printf("%d\n",b );
return 0;
}
