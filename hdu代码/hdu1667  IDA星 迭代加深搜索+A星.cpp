#include <bits/stdc++.h>
using namespace std;

const int center[] = {6,7,8,11,12,15,16,17};  //����8��������
const int reverseop[] = {5,4,7,6,1,0,3,2,-1};  //ÿ�ֲ����������
const int index[8][7] = {  //��A-H�����䶯���±�
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
char finop[105];  //�ѵ�Ŀ��Ĳ�������
bool flag;  //�Ƿ��ѵ�Ŀ��

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

void dfs(int depth,int lastop,int maxdepth)  //depth��ǰ��� lastop��һ�εĲ��� maxdepthÿ�ε�������������������
{
    if(flag) return;
    if(depth>maxdepth || depth+get_h()>maxdepth) return;  //�����Լ�֦
    if(get_h()==0)  //������ͬ��
    {
        flag=true;
        finop[depth]='\0';
        printf("%s\n%d\n",finop,mp[center[0]]);
        return;
    }
    for(int nextop=0;nextop<8;nextop++)  //��A��ʼ����
    {
        if(nextop!=reverseop[lastop])  //����һ�β���������
        {
            option(nextop);
            finop[depth]=nextop+'A';
            dfs(depth+1,nextop,maxdepth);
            option(reverseop[nextop]);  //���ݻ�ԭ
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
        for(int depth=1;!flag;depth++) //��������
        {
            dfs(0,8,depth);
        }
    }
    return 0;
}
