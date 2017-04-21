#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 1e7+9;
const int maxn = 10005;
int sz[maxn][25],vis[maxn],dp[maxn][25],n,m;
//dp[i][j]��ʾi���Ϳj��ɫ��Ϳ������
vector<int>ve[maxn];//�޸�ͼ�����
vector<int>tree[maxn];//�и�ͼ�����

void init()
{
    for(int i=1;i<=n;i++) ve[i].clear();
    for(int i=1;i<=n;i++) tree[i].clear();
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
}

void build(int root) //���޸�ͼ��Ϊ�и�ͼ
{
    if(vis[root]) return;
    vis[root]=1;
    for(int i=0;i<ve[root].size();i++)
    {
        int son = ve[root][i];
        if(!vis[son])
        {
            tree[root].push_back(son);
            build(son);
        }
    }
}

void dfs(int root)
{
    if(!tree[root].size()) //Ҷ�ӽ��
    {
        for(int i=1;i<=m;i++)
        {
            if(sz[root][i]) dp[root][i]=1;
            else dp[root][i]=0;
        }
        return;
    }
    for(int i=0;i<tree[root].size();i++) //�ȵݹ�����ӽ���dp
    {
        dfs(tree[root][i]);
    }
    for(int i=1;i<=m;i++)
    {
        if(sz[root][i])
        {
            ll sum=1;
            for(int j=0;j<tree[root].size();j++)
            {
                ll tmp=0;
                int son = tree[root][j];
                for(int k=1;k<=m;k++)
                {
                    if(k!=i) tmp = (tmp+dp[son][k])%mod; //����������ӽڵ��ٸýڵ�Ϳi������Ϳ��
                }
                sum = (sum*tmp)%mod; //��������ýڵ�Ϳi��ɫʱ����Ϳ��
            }
            dp[root][i] = sum;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            ve[a].push_back(b);
            ve[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&sz[i][j]);
            }
        }
        build(1); //1Ϊ��
        dfs(1); //�Ӹ���ʼ����
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            ans = (ans+dp[1][i])%mod; //����������ڵ�����Ϳ������
        }
        printf("%lld\n",ans);
    }
    return 0;
}
