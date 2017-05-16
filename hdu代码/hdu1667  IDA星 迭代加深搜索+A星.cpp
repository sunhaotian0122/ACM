#include <bits/stdc++.h>
using namespace std;

const int center[] = {6,7,8,11,12,15,16,17};  //中心8个点坐标
const int reverseop[] = {5,4,7,6,1,0,3,2,-1};  //每种操作的逆操作
const int index[8][7] = {  //从A-H操作变动的下标
    { 0,2,6,11,15,20,22 },    //A
    { 1,3,8,12,17,21,23 },    //B
    { 10,9,8,7,6,5,4 },       //C
    { 19,18,17,16,15,14,13 }, //D
    { 23,21,17,12,8,3,1 },    //E
    { 22,20,15,11,6,2,0 },    //F
    { 13,14,15,16,17,18,19 }, //G
    { 4,5,6,7,8,9,10 },       //H
};
int mp[24];
char finop[105];  //搜到目标的操作序列
bool flag;  //是否搜到目标

int get_h()
{
    int cnt[3]={0};
    int num=-1;
    for(int i=0;i<8;i++)
    {
        cnt[mp[center[i]]-1]++;
        num = max(num,cnt[mp[center[i]]-1]);
    }
    return 8-num;
}

void option(int op)
{
    int tmp=mp[index[op][0]];
    for(int i=0;i<6;i++)
    {
        mp[index[op][i]] = mp[index[op][i+1]];
    }
    mp[index[op][6]]=tmp;
}

void dfs(int depth,int lastop,int maxdepth)  //depth当前深度 lastop上一次的操作 maxdepth每次迭代加深搜索的最大深度
{
    if(flag) return;
    if(depth>maxdepth || depth+get_h()>maxdepth) return;  //可行性剪枝
    if(get_h()==0)  //中心相同了
    {
        flag=true;
        finop[depth]='\0';
        printf("%s\n%d\n",finop,mp[center[0]]);
        return;
    }
    for(int nextop=0;nextop<8;nextop++)  //从A开始搜索
    {
        if(nextop!=reverseop[lastop])  //与上一次操作不互逆
        {
            option(nextop);
            finop[depth]=nextop+'A';
            dfs(depth+1,nextop,maxdepth);
            option(reverseop[nextop]);  //回溯还原
        }
    }
}

int main()
{
    while(1)
    {
        for(int i=0;i<24;i++)
        {
            scanf("%d",&mp[i]);
            if(mp[i]==0) return 0;
        }
        if(get_h()==0)
        {
            printf("No moves needed\n%d\n", mp[center[0]]);
            continue;
        }
        flag=false;
        for(int depth=1;!flag;depth++) //迭代加深
        {
            dfs(0,8,depth);
        }
    }
    return 0;
}
