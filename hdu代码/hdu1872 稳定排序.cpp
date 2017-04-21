#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct data{
    string x;
    int y;
}sz[305],tmp[305];

/*void swap(data *a,data *b)
{
    string cmp;
    int k;
    cmp=a->x;
    a->x=b->x;
    b->x=cmp;
    k=a->y;
    a->y=b->y;
    b->y=k;
}*/

int ju(data sz[],int n)
{
    int judge = 1;
    for(int j=2;j<=n;j++)
    {
        int i=j-1;
        data key=sz[j];
        while(i>0&&sz[i].y<key.y)
        {
            sz[i+1]=sz[i];
            i -= 1;
        }
        sz[i+1]=key;
    }
    for(int j=1;j<=n;j++)
    {
        if(sz[j].x!=tmp[j].x&&sz[j].y==tmp[j].y)
        {
            judge=2;
        }
        if(sz[j].y!=tmp[j].y)
        {
            judge=3;
            break;
        }
    }
    return judge;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) cin>>sz[i].x>>sz[i].y;
        for(int i=1;i<=n;i++) cin>>tmp[i].x>>tmp[i].y;
        int ans = ju(sz,n);
        if(ans==1) printf("Right\n");
        else if(ans==2)
        {
            printf("Not Stable\n");
            for(int i=1;i<=n;i++) cout<<sz[i].x<<" "<<sz[i].y<<endl;
        }
        else
        {
            printf("Error\n");
            for(int i=1;i<=n;i++) cout<<sz[i].x<<" "<<sz[i].y<<endl;
        }
    }
    return 0;
}
