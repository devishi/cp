#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001
int time=0;
int count=0;
enum 
{
    white, gray, black
}color;
typedef struct _Node
{
    int dest;
    int color;
    struct _Node* next;
}Node;

typedef struct _Adj
{
    Node *list; 
}Adj;
int n[MAX];
int D[MAX];
int F[MAX];
int Color[MAX];
void countSort(int a[], int n)
{
    if(n <= 0)
        return;
        
    int i;
    int max = -10000;
    
    for(i = 0; i < n ; i++)
        if(a[i] > max)
            max = a[i];
    
    int count[max+1];
    for(i = 0 ; i <= max; i++)
        count[i] = 0;
    
    for(i = 0; i < n; i++)
    {
        int ele = a[i];
        count[ele] = count[ele] + 1;
    }
    
    for(i = 1 ; i <= max; i++)
        count[i] = count[i] + count[i-1];
    
    int result[n];
    
    for(i = 0; i < n ; i++)
    {
        int ele = a[i];
        int loc = count[ele] - 1;
        result[loc] = ele;
        count[ele] = count[ele] - 1;
    }
    
    for(i =0; i < n; i++)
        a[i] = result[i];
    
}
void printGraph(Adj *list, int vertices);
void addEdge(Adj *list, int start, int end);
void DFS(Adj* list, int vertex);

int i=0;
int main(int argc, char **argv)
{
 
int vertex1=0, vertex2=0;
int vertex_count=0;
Node *head = NULL;

int v=1,m;
int u=1,j;
int connected_components = 0;
scanf("%d",&vertex_count);
int vertices = vertex_count + 1;

//Create the struct pointer and call the function to create the Graph
Adj* list = (Adj*)malloc(sizeof(Adj)*vertices);

for(v=1; v<vertices; v++){
    Color[v] = white;
}
scanf("%d",&m);
while(m--)
{   
    scanf("%d %d",&vertex1,&vertex2); 
    addEdge(list, vertex1, vertex2);
}

Node *temp;

//run through the graph's nodes
for (v = 1; v < vertices; v++)
 {
    count = 0;
    if(Color[v] == white){
        DFS(list, v);
        i+=1;
        connected_components++;

    }
 }

printf("%d\n", connected_components);
countSort(n,connected_components);
for(j=connected_components-1;j>=0;j--)
    printf("%d\n", n[j]);

free(list);

return 0;
}
 void DFS(Adj* list, int vertex)
{
count++;

Color[vertex] = gray;

time = time + 1;
D[vertex] = time;
Node *temp;

for(temp = list[vertex].list; temp != NULL; temp = temp->next)
{   
        if(Color[temp->dest] == white)
            DFS(list, temp->dest);
}
time = time+1;
F[vertex] = time;
//printf("count is %d\n",count );
n[i]=count;
Color[vertex] = black;
 }
void addEdge(Adj* list, int v, int dest)
{

Node* temp = (Node*)malloc(sizeof(Node));
temp->next = list[v].list;
temp->dest = dest;
list[v].list = temp;

Node* temp2 = (Node*)malloc(sizeof(Node));
temp2->next = list[dest].list;
temp2->dest = v;
list[dest].list = temp2;
}