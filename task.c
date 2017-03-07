#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *next;
    int vertex;
}node;

int n,flag;
 
int visited[100001];
int DFS(node **G,int i,int s,int q)
{
    node *p;
    //printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    if (i==q)
    {
        flag=1;
        //printf("%d\n",s );
        return s;
    }
    
    while(flag!=1 && p!=NULL)
    {
       i=p->vertex;
    //printf("neuuh\n");   
       if(!visited[i])
            DFS(&G,i,s,q);
    s+=1;
        p=p->next;
    }
}
 void insert(node **G,int vi,int vj)
{
    node *p,*q;
    q=(node*)malloc(sizeof(node));
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
void read_graph(node **G)
{
    int i,vi,vj,no_of_edges;
    //printf("Enter number of vertices:");
   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        G[i]=NULL;
        //printf("Enter number of edges:");
           scanf("%d",&no_of_edges);
 
           for(i=0;i<no_of_edges;i++)
        {
            //printf("Enter an edge(u,v):");
            scanf("%d%d",&vi,&vj);
            insert(&G,vi-1,vj-1);
        }
    }
}
int main()
{
    int i,t;
    scanf("%d",&t);
    while(t--)
    {
        node *G[100001];  
        int n,m,k,s,l,q;
        read_graph(&G);
        flag=0;
        s=0;
        for(i=0;i<n;i++)
            visited[i]=0;
        //scanf("%d",&m);
        //scanf("%d",&q);
        l=DFS(&G,0,s,n-1);
        if(l!=0)
            printf("%d\n",s );
        else if(l<=0)
            printf("-1\n");
    }
    return 0;
}