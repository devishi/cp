#include <iostream>
using namespace std;

#define ROW 7
#define COL 7
#define infi 5000  //infi for infinity
class prims
{
   int graph[ROW][COL],nodes;
   public:
   prims();
   void createGraph();
   void primsAlgo();
   bool checkforcrossline(int*,int,int);
};

prims :: prims(){
     for(int i=0;i<ROW;i++)
       for(int j=0;j<COL;j++)
     graph[i][j]=0;
}

void prims :: createGraph(){
    int i,j;
    cout<<"Enter Total Nodes : ";
    cin>>nodes;
    cout<<"\n\nEnter Adjacency Matrix : \n";
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
        cin>>graph[i][j];

    //Assign infinity to all graph[i][j] where weight is 0.
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
           if(graph[i][j]==0)
          graph[i][j]=infi;
        }
    }
}

void prims :: primsAlgo(){
    int selected[ROW],i,j,ne; //ne for no. of edgesintfalse=0,true=1,min,x,y;
    int min,x,y;
    int Answer=0;
    for(i=0;i<nodes;i++)
       selected[i]=false;

    selected[0]=true;
    ne=0;

    while(ne < nodes-1){
       min=infi;

       for(i=0;i<nodes;i++)
       {
          if(selected[i]==true)
          {
              for(j=0;j<nodes;j++)
              {
                if(selected[j]==false)
                {
                    if((min > graph[i][j]) && checkforcrossline(selected,i,j))
                    {
                        min=graph[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
          }
       }
       selected[y]=true;
       cout<<"\n"<<x+1<<" --> "<<y+1;
       Answer+=graph[x][y];
       ne=ne+1;
    }
    cout<<"\nCost : "<<Answer ;
}

bool prims :: checkforcrossline(int* selectedArr,int n1,int n2)
{
    int big,small;
    if(n1>n2)
    {
        big=n1;small=n2;
    }
    else
    {
        big=n2;small=n1;
    }

    int restNodes[ROW];
    int count=0;
    for(int i=0;i<small;i++)
    {
        if(selectedArr[i]==true)
            {
                restNodes[count]=i;
                count++;
            }
    }
    for(int j=big+1;j<nodes;j++)
    {
         if(selectedArr[j]==true)
            {
                restNodes[count]=j;
                count++;
            }
    }


    int start=small+1;
    int end = big;
    for(;start<end;start++)
    {
        if(selectedArr[start] == true)
        {
            for(int find=0;find<count;find++)
            {
                if(graph[start][restNodes[find]]!= infi)
                    return false;
            }
        }
    }
    return true;
}

int main(){
    prims MST;

    cout<<"\nPrims Algorithm to find Minimum Spanning Tree\n";
    MST.createGraph();
    MST.primsAlgo();
return 0;
}