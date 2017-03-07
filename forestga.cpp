#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct node
{
    long long int h;
    long long int r;
    long long int m;
}tree[100010];

bool differ(struct node x,struct node y)
{
    return x.m<y.m;
}

int main()
{
    int i;
    long long int n,w,l;
    long long int p=0,rate=0,month=0,inc=0,newrate,newtime;
    cin>>n;
    cin>>w;
    cin>>l;
    for(i=0;i<n;i++)
    {
        cin>>tree[i].h;
        cin>>tree[i].r;
        if(tree[i].h>=l)
            tree[i].m=0;
        else if((l-tree[i].h)%tree[i].r==0)
            tree[i].m=(l-tree[i].h)/tree[i].r;
        else
            tree[i].m=((l-tree[i].h)/tree[i].r)+1;
    }
    sort(tree,tree+n,differ);
    for(i=0;i<n;i++)
    {
        if(p>=w)
            break;
        if(i==0)
        {
            p=tree[i].h+(tree[i].r*tree[i].m);
            rate=tree[i].r;
            month=tree[i].m;
        }
        else
        {
            
            if((p+(rate*(tree[i].m-(tree[i-1].m)-1)))<w)
            {
                p=p+tree[i].h+(tree[i].r*tree[i].m)+(rate*(tree[i].m-tree[i-1].m));
                rate+=tree[i].r;
                month=tree[i].m;
            }
            else
            {
                if((w-p)%rate==0)
                    inc=(w-p)/rate;
                else
                    inc=((w-p)/rate)+1;
                month+=inc;
                p=p+(rate*inc);
                break;
            }
        }

    }
    if(p<w)
    {
        if((w-p)%rate==0)
            inc=(w-p)/rate;
        else
            inc=((w-p)/rate)+1;
        month+=inc;
        p=p+(rate*inc);
    }
    cout<<month;
    cout<<"\n";
    return 0;
}
