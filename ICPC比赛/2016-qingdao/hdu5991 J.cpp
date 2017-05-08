#include <bits/stdc++.h>
using namespace std;

int sz[105][105];
int root[105];
int ans;

int myFind(int x)
{
    return root[x]==x ? x : myFind(root[x]);
}

void myUnion(int a,int b)
{
    int x = myFind(a);
    int y = myFind(b);
    if(x!=y)
    {
        root[max(x,y)] = root[min(x,y)];
    }
    else ans++;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) root[i]=i;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&sz[i][j]);
                if(j>i&&sz[i][j]) myUnion(i,j);
            }
        }
        bool flag=true;
        int tmp = myFind(1);
        for(int i=2;i<=n;i++)
        {
            if(tmp!=myFind(i))
            {
                flag=false;
                break;
            }
        }
        if(flag) printf("Case #%d: %d\n",ca,ans);
        else printf("-1\n");
    }
    return 0;
}
