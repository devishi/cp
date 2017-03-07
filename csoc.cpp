#include<iostream>
#include <list>

using namespace std;
 
class Graph
{
    int V;    
    list<int> *adj; 
    void totalpathsu(int , int , bool [], int [], int &,int );
 
public:
    Graph(int V);  
    void addEdge(int u, int v);
    void totalpaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); 
}

void Graph::totalpaths(int s, int d)
{
    int m=0;
    bool *visited = new bool[V];
    int *path = new int[V];
    int number = 0; 
    for (int i = 0; i < V; i++)
        visited[i] = false;
    totalpathsu(s, d, visited, path, number,m);
}

void Graph::totalpathsu(int u, int d, bool visited[],int path[], int &number,int m)
{
    visited[u] = true;
    path[number] = u;
    number++;
    if (u == d)
    {
        for (int i = 0; i<number; i++)
            cout << path[i] << " ";
        cout << endl;
        
    }
    else 
    {
        
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                totalpathsu(*i, d, visited, path, number,m);
    }
    number--;
    visited[u] = false;

}
 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,M,i,s;
        cin>>N;
        cin>>M;
        cin>>s;
        Graph g(N);
        int a[M];
        for (i = 0; i < M; i++)
            a[i] = false;
        for(i=0;i<M;i++)
        {
            cin>>a[i];
            if(i + a[i]<N && i+a[i]>=0)
                g.addEdge(i, i+a[i]);
            if(i-a[i]>=0)
                g.addEdge(i, i-a[i]);
        }

        for(i=0;i<N;i++)
        {
            g.totalpaths(s-1, i);
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}