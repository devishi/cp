#include <bits/stdc++.h>

using namespace std;

#define ROW 100
#define COL 100

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) &&(col >= 0) && (col < COL);
}

struct cord
{
    int x;
    int y;
};

struct next
{
    cord pt;  
    int dist;  
};
 
int BFS(int mat[][COL], cord src, cord dest)
{
    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return INT_MAX;
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);
    visited[src.x][src.y] = true;
    queue<next> q;
    next s = {src, 0};
    q.push(s); 
    while (!q.empty())
    {
        next curr = q.front();
        cord pt = curr.pt;
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            if (isValid(row, col) && mat[row][col] && 
               !visited[row][col])
            {
                visited[row][col] = true;
                next Adjcell = { {row, col},curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
    return INT_MAX;
}
int main()
{
    int t;
    scanf("%d",&t);
    int n,m,k1,k2,i,j,d,gcd,u,v;
    float q;
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&k1,&k2);
        int mat[ROW][COL] ;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&d);
                mat[i][j]=1-d;
            }
        }
        cord source = {0, 0};
        cord dest = {0, m-1};
        int dist = BFS(mat, source, dest);
        if(k2==0 && k1!=0)
            v=k1;
        else if(k1==0 && k2!=0)
            v=k2;
        else if(k1==0 && k2==0)
        {
            v=1;
            dist=-1;
        }
        else
        {
            if(k1>k2)
                v=k1;
            else
                v=k2;
        }
        u=dist/(v*2) ;
        if (dist != INT_MAX )
        {
            if(dist%(2*v)==0)
                cout << u << "\n";
            else
                cout << u+1 << "\n";
        }
        else
            cout << "-1" << "\n";
    }
    return 0;
}