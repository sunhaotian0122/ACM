#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

const int maxn = 505;
int son[maxn];
bool flag;
vector<int> edge[maxn];

void dfs(int root)
{
    int num=0;
    son[root] = 1;
    for(int i=0;i<edge[root].size();i++)
    {
        int to = edge[root][i];
        dfs(to);
        son[root] += son[to];
        if(son[to]%2==1) num++;
    }
    if(num>=2) flag = true;
}

int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        memset(son,0,sizeof(son));
        for(int i=1;i<=n;i++) edge[i].clear();
        int tmp;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&tmp);
            edge[tmp].push_back(i);
        }
        flag = false;
        dfs(1);
        if(flag || n&1) printf("Alice\n");
        else if(n/2-1>k) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
