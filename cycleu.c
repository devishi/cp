#include<stdio.h>
#include<stdlib.h>
int visited[10]={0,0,0,0};//take it to the no of nodes in graph ,or allocate memory dynamically
int flag=0;
int m=0;
struct node
{
    int a;
    struct node * next;
};
struct graph
{
    int v;
    struct node **array;
};
void addedge(struct graph *g,int s,int d)
{
    struct node*temp ;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->a=d;
    temp->next=g->array[s];// adding the node at the starting of the list
    g->array[s]=temp;
}
void dfs(int x,struct graph *g)
{
struct node *temp;
if(visited[x]==1)
{
   flag=1;
   m+=1;
   return;
}
else
   {
       printf("%d",x);
       visited[x]=1;

temp=g->array[x];
while(temp)
{
    dfs(temp->a,g);
    temp=temp->next;
}
   }
   return;
}

int main()
{
struct graph *g;
g=(struct graph *)malloc(sizeof(struct graph));
g->v=4;
g->array=(struct node **)malloc(5*sizeof(struct node*));
int i;
for(i=0;i<4;i++) //intializing the graph
{
    struct node *n;
    n= (struct node*)malloc(sizeof(struct node));
    n->a=i;
    n->next=NULL;
    g->array[i]=n;
}

dfs(2,g);
printf("\n");
if(flag)
printf("There exists a cycle");
else
printf("There does not exists a cycle");
return 0;
}