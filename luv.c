#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int vertex;
    struct edge *next;
};

struct edge *add(struct edge *head, int newvertex)
{
    struct edge *tail;
    struct edge *temp=head;//,*z;
    struct edge *z=temp;
    while(temp!=NULL){
        z=temp;
        temp=temp->next;
    }
    struct edge *newhead=(struct edge *)malloc(sizeof(struct edge *));
    newhead->vertex=newvertex;
    newhead->next=NULL;
    if(head==NULL)
        head=newhead;
    else
        z->next=newhead;
    return newhead;
}
int arr[100005],k;
int flag;
void dfs(struct edge *list[], int i, int visited[],int top1,int *stack1)
{
    struct edge *p;
    top1++;
    stack1[top1]=i;
    visited[i]=1;
    int j=i;
    //printf("%d ", i);
    p=list[i];
    //visited[i]=1;
    while(p!=NULL)
    {
        i=p->vertex;
        //printf("%d\n",i );
        if(visited[i]==0)
        {
            dfs(list, i, visited,top1,stack1);
        }
        else if (visited[i]==1)
            flag=1;
        p=p->next;
    }
    visited[j]=2;
    arr[k++]=j;
}

int makeadjlist(struct edge *list1[], int vertices,int j)
{
    int i;
    int v1, v2;
    scanf("%d", &v2);
    int no=j;
    list1[j]=add(list1[j], v2);
    //printf("List is\n");
    /*for(i=1; i<=vertices; i++)
    {
        printf("adjacencylist[%d] -> ", i);
        struct edge *traverse=list1[i];
        while(traverse!=NULL)
        {
            printf("%d -> ", traverse->vertex);
            traverse=traverse->next;
        }
        printf("NULL\n");
    }*/
    return no;

}
//int toposort(struct edge *list1[],int vertices)
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    int stack1[100000];
    int top1=-1;

    int vertices, i, n,j,q;
    //printf("Enter the number of vertices and edges\n");
    scanf("%d", &vertices);
    struct edge *list1[vertices+1];
    int visited[vertices+1];
        for(i=0; i<=vertices; i++)
    {
        list1[i]=NULL;
    }
    for(i=1;i<=vertices;i++)
    {
        scanf("%d",&q);
        for(j=1;j<=q;j++)
            makeadjlist(list1,vertices,i);
    }
    for(i=0; i<vertices+1; i++)
        visited[i]=0;
    int fuck,flag=0;
    k=0;
    for(j=0; j<vertices+1; j++)
            visited[j]=0;
    for(i=1; i<=vertices; i++)
    {
        
        //printf("DFS of list 1 with %d\n", i);
        if(visited[i]==0)
            dfs(list1, i, visited,top1,stack1);

        //printf("INCOMING STACK\n");
        // for(fuck=0; fuck<=top1; fuck++)
        // {
        //     printf("%d  ", stack1[fuck]);
        // }
        top1=-1;
    }
    if(flag==1)
        printf("FAIL\n");
    else
        for(i=k-1;i>=0;i--)
            printf("%d\n",arr[i] );
}
//printf("\n");
//  int i, j;
    return 0;
}
 