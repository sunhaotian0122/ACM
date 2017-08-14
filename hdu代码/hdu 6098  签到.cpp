#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

const int maxn = 1e5+5;
struct Node{
    int a,num;
}node[maxn];

bool cmp(Node a,Node b)
{
    return a.a>b.a;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&node[i].a);
            node[i].num=i;
        }
        sort(node+1,node+n+1,cmp);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(node[j].num%i!=0)
                {
                    if(i==n) printf("%d\n",node[j].a);
                    else printf("%d ",node[j].a);
                    break;
                }
            }
        }
    }
    return 0;
}
