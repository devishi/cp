#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int x;
    struct queue *next;
}queue;

typedef struct listnode{
    int id;
    struct listnode *next;
}listnode;

typedef struct adjlist{
    listnode *head;
}adjlist;

typedef struct graph{
    int vertices;
    adjlist *array;
}graph;

void enqueue(queue **head , queue **tail , int n)
{   
    if(*head==NULL)
    {   
        queue *temp=malloc(sizeof(queue));
        temp->x=n;
        temp->next=NULL;
        *head=temp;
        *tail=temp;
        return;
    }
    else
    {   
        queue *temp=malloc(sizeof(queue));
        temp->x=n;
        temp->next=NULL;
        (*tail)->next=temp;
        *tail=temp;
        return;
    }
}

int qempty(queue **head)
{
    if(*head==NULL)
    {
        return 0;
    }
    return 1;
}

int dequeue(queue **head , queue **tail)
{
    int t=(*head)->x;
    queue *temp=*head;
    (*head)=temp->next;
    free(temp);
    temp=NULL;
    return t;
}

listnode *newnode(int id)
{
    listnode *node=malloc(sizeof(listnode));
    node->id=id;
    node->next=NULL;
    return node;
}

void creategraph(graph **g , int v)
{
    *g=(graph *)malloc(sizeof(graph));
    (*g)->vertices=v;
    (*g)->array=(adjlist *)malloc(v*sizeof(adjlist));
    int i;
    for(i=0;i<v;++i)
    {
        (*g)->array[i].head=NULL;
    }
}

void addedge(graph **g , int u , int v)
{   
    listnode *node=newnode(v);
    node->next=(*g)->array[u].head;
    (*g)->array[u].head=node;
    node=newnode(u);
    node->next=(*g)->array[v].head;
    (*g)->array[v].head=node;
}


void toputil(graph **g,int v,int *visited)
{
    visited[v]=1;
    int i;
    queue *head=NULL,*tail=NULL;
    enqueue(&head,&tail,v);
    listnode *temp=(*g)->array[p].head;
    int p=dequeue(&head,&tail);
    while(temp)
    {   
        if(!visited[temp->id])
        {   
            DFS(g,temp->id,visited[]);            
        }
        temp=temp->next;
    }
}


void bfs(graph **g , int v , int *visited , int *level)
{
    visited[v]=1;
    level[v]=0;
    queue *head=NULL,*tail=NULL;
    enqueue(&head,&tail,v);
    while(qempty(&head))
    {   
        int p=dequeue(&head,&tail);
        listnode *temp=(*g)->array[p].head;
        while(temp)
        {   
            if(!visited[temp->id])
            {   
                visited[temp->id]=1;
                level[temp->id]=level[p]+1;
                ans += level[temp->id];
                enqueue(&head,&tail,temp->id);
            }
            temp=temp->next;
        }
    }
}
