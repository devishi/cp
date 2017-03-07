#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int i,j,k,l,sum=0;
    char a[1000005];
    cin >> a;
    for(i=0;i<a.length()-4;i++)
    {
        for(j=i+4;j<a.length();j++)
            if(a[i]==a[j])
            {
                for(k=i+1;k<j-1;k++)
                    for(l=k+1;l<j;l++)
                        if(a[k]==a[l])
                            sum++;
            }
    }
    return 0;
}