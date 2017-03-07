#include <stdio.h>
#include <stdlib.h>
#define MAX 100  
 
#define initial 1
#define waiting 2
#define visited 3

int n;    
int adj[MAX][MAX];
int state[MAX]; 
void create_graph();
void BF_Traversal();
void BFS(int v);
 
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main()
{
  int t,n,m;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&m);
    create_graph(n,m);
    BF_Traversal();
  } 
  return 0;
}

    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);