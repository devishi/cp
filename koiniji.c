#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

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

void enqueue(Q *,int);
int dequque(Q *);
int empty(Q *);
int full(Q *);
void BFS(int v,int s,int k);
void readgraph(int n,int s,int k);      
void insert(int vi,int vj);     
void DFS(int i);
int visited[MAX];
node *G[MAX];          
int n;                

void main()
{
 int i,op;
  int m,n,s,k;
  scanf("%d",&n);
  scanf("%d",&s);
  scanf("%d",&k);
  readgraph(n,s,k);
  while(k--)
  {
    scanf("%d",&i);
    BFS(i,s,k);
  }
}


void BFS(int v,int s,int k)
{
 int w,i,visited[MAX];
 Q q;
 int m;

 node *p;
 q.R=q.F=-1;              //initialise
 for(i=0;i<n;i++)
  visited[i]=0;
 enqueue(&q,v);
 //printf("\nVisit\t%d",v);
 if(m<v)
  m=v;
 visited[v]=1;
 while(!empty(&q))
 {
  v=dequeue(&q);
  for(p=G[v];p!=NULL;p=p->next)
  {
   w=p->vertex;
   if(visited[w]==0)
   {
    enqueue(&q,w);
    visited[w]=1;
    if(m<w)
      m=w;
    //printf("\nvisit\t%d",w);
   }
  }
 }
 if(s==0)
  m=0;
 printf("%d\n",m );
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

void readgraph(int n,int s,int k)
{  int i,vi,vj,no_of_edges;


 for(i=0;i<n;i++)
  G[i]=NULL;
 
 //printf("\nEnter no of edges :");
 //scanf("%d",&no_of_edges);
 for(i=0;i<s;i++)
 {
  //printf("\nEnter an edge (u,v)  :");
  scanf("%d%d",&vi,&vj);
  insert(vi,vj);
  insert(vj,vi);
 }
}

void insert(int vi,int vj)
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