#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};
 
struct queueNode
{
    Point pt;  
    int dist; 
};
 

bool isValid(int row, int col,int ROW,int COL)
{
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}
 
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
 
int BFS(int ROW,int COL,int mat[100][100],Point src, Point dest)
{
    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return INT_MAX;
 
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    visited[src.x][src.y] = true;
    queue<queueNode> q;

    queueNode s = {src, 0};
    q.push(s);  
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
 
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
         
            if (isValid(row, col,ROW,COL) && mat[row][col] && 
               !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},curr.dist + 1 };
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
	int n,m,k1,k2,i,j;
    int mat[100][100];
    while(t--)
	{
		scanf("%d %d %d %d",&(n+1),&(m+1),&k1,&k2);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%d",&mat[i][j]);
		}
		Point source = {1, 0};
    	Point dest = {1, m};
		int dist = BFS(n,m,	mat, source, dest);
    	if (dist != INT_MAX)
        	cout << dist ;
    	else
        	cout << "-1";
	}
    return 0;
}