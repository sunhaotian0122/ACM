#include <bits/stdc++.h>
using namespace std;

int sz[7][5];  //二阶魔方

void change(int a,int b)  //a：1为上，2为前，3为右 b：0为顺时针，1为逆时针
{
    if(a==1&&b==0)
    {
        int tmp1=sz[2][1];
        int tmp2=sz[2][2];
        sz[2][1] = sz[5][2],sz[2][2] = sz[5][4];
        sz[5][2] = sz[4][4],sz[5][4] = sz[4][3];
        sz[4][4] = sz[6][3],sz[4][3] = sz[6][1];
        sz[6][3] = tmp1,sz[6][1] = tmp2;
    }
    if(a==1&&b==1)
    {
        int tmp1=sz[2][1];
        int tmp2=sz[2][2];
        sz[2][1] = sz[6][3],sz[2][2] = sz[6][1];
        sz[6][3] = sz[4][4],sz[6][1] = sz[4][3];
        sz[4][4] = sz[5][2],sz[4][3] = sz[5][4];
        sz[5][2] = tmp1,sz[5][4] = tmp2;
    }
    if(a==2&&b==0)
    {
        int tmp1=sz[1][3];
        int tmp2=sz[1][4];
        sz[1][3] = sz[5][3],sz[1][4] = sz[5][4];
        sz[5][3] = sz[3][2],sz[5][4] = sz[3][1];
        sz[3][2] = sz[6][3],sz[3][1] = sz[6][4];
        sz[6][3] = tmp1,sz[6][4] = tmp2;
    }
    if(a==2&&b==1)
    {
        int tmp1=sz[1][3];
        int tmp2=sz[1][4];
        sz[1][3] = sz[6][3],sz[1][4] = sz[6][4];
        sz[6][3] = sz[3][2],sz[6][4] = sz[3][1];
        sz[3][2] = sz[5][3],sz[3][1] = sz[5][4];
        sz[5][3] = tmp1,sz[5][4] = tmp2;
    }
    if(a==3&&b==0)
    {
        int tmp1=sz[1][2];
        int tmp2=sz[1][4];
        sz[1][2] = sz[2][2],sz[1][4] = sz[2][4];
        sz[2][2] = sz[3][2],sz[2][4] = sz[3][4];
        sz[3][2] = sz[4][2],sz[3][4] = sz[4][4];
        sz[4][2] = tmp1,sz[4][4] = tmp2;
    }
    if(a==3&&b==1)
    {
        int tmp1=sz[1][2];
        int tmp2=sz[1][4];
        sz[1][2] = sz[4][2],sz[1][4] = sz[4][4];
        sz[4][2] = sz[3][2],sz[4][4] = sz[3][4];
        sz[3][2] = sz[2][2],sz[3][4] = sz[2][4];
        sz[2][2] = tmp1,sz[2][4] = tmp2;
    }
}

bool judge()
{
    int n=0,c[7];
    bool flag;
    for(int i=1;i<=6;i++)
    {
        flag=true;
        for(int j=1;j<=4;j++)
        {
            if(j>1&&sz[i][j]!=sz[i][j-1]) flag=false;
        }
        if(flag)
        {
            n++;
            c[i]=sz[i][1];
        }
        else return false;
    }
    if(n==6)
    {
        flag=true;
        for(int i=1;i<6;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                if(c[i]==c[j]) flag=false;
            }
        }
        if(flag) return true;
        else return false;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int num=0,n[7],c[7];
        bool flag,color=true;
        for(int i=1;i<=6;i++)
        {
            flag=true;
            for(int j=1;j<=4;j++)
            {
                scanf("%d",&sz[i][j]);
                if(j>1&&sz[i][j]!=sz[i][j-1]) flag=false;
            }
            if(flag)
            {
                num++;
                n[i]=1;
                c[i]=sz[i][1];
            }
            else n[i]=0;
        }
        if(num==6)
        {
            for(int i=1;i<6;i++)
            {
                for(int j=i+1;j<=6;j++)
                {
                    if(c[i]==c[j]) color=false;
                }
            }
            if(color) printf("YES\n");
            else printf("NO\n");
        }
        else if(num==2)
        {
            if(n[1]==1&&n[3]==1)
            {
                change(1,0);
                if(judge())
                {
                    printf("YES\n");
                    continue;
                }
                change(1,1);
                change(1,1);
                if(judge())
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else if(n[2]==1&&n[4]==1)
            {
                change(2,0);
                if(judge())
                {
                    printf("YES\n");
                    continue;
                }
                change(2,1);
                change(2,1);
                if(judge())
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else if(n[5]==1&&n[6]==1)
            {
                change(3,0);
                if(judge())
                {
                    printf("YES\n");
                    continue;
                }
                change(3,1);
                change(3,1);
                if(judge())
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else printf("NO\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
