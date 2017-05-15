#include <bits/stdc++.h>
using namespace std;

char str[105];
char sz[30];

void init()
{
    sz[1]=sz[2]=sz[3]=sz[4]='Y';
    sz[5]=sz[6]=sz[7]=sz[8]='R';
    sz[9]=sz[10]=sz[11]=sz[12]='O';
    sz[13]=sz[14]=sz[15]=sz[16]='B';
    sz[17]=sz[18]=sz[19]=sz[20]='G';
    sz[21]=sz[22]=sz[23]=sz[24]='W';
}

void change_1(int flag) //true为顺时针
{
    char a,b;
    if(flag)
    {
        a = sz[1];
        sz[1] = sz[3];
        sz[3] = sz[4];
        sz[4] = sz[2];
        sz[2] = a;
        a = sz[9],b=sz[10];
        sz[9]=sz[13],sz[10]=sz[14];
        sz[13]=sz[5],sz[14]=sz[6];
        sz[5]=sz[17],sz[6]=sz[18];
        sz[17]=a,sz[18]=b;
    }
    else
    {
        a = sz[1];
        sz[1]=sz[2],sz[2]=sz[4],sz[4]=sz[3],sz[3]=a;
        a = sz[9],b=sz[10];
        sz[9]=sz[17],sz[10]=sz[18];
        sz[17]=sz[5],sz[18]=sz[6];
        sz[5]=sz[13],sz[6]=sz[14];
        sz[13]=a,sz[14]=b;
    }
}

void change_2(int flag) //true为顺时针
{
    char a,b;
    if(flag)
    {
        a = sz[5];
        sz[5] = sz[7],sz[7] = sz[8],sz[8] = sz[6],sz[6] = a;
        a = sz[3],b=sz[4];
        sz[3]=sz[16],sz[4]=sz[14];
        sz[16]=sz[22],sz[14]=sz[21];
        sz[22]=sz[17],sz[21]=sz[19];
        sz[17]=a,sz[19]=b;
    }
    else
    {
        a = sz[5];
        sz[5] = sz[6],sz[6] = sz[8],sz[8] = sz[7],sz[7] = a;
        a = sz[3],b=sz[4];
        sz[3]=sz[17],sz[4]=sz[19];
        sz[17]=sz[22],sz[19]=sz[21];
        sz[22]=sz[16],sz[21]=sz[14];
        sz[16]=a,sz[14]=b;
    }
}
void change_3(int flag) //true为顺时针
{
    char a,b;
    if(flag)
    {
        a = sz[9];
        sz[9] = sz[11],sz[11] = sz[12],sz[12] = sz[10],sz[10] = a;
        a = sz[1],b=sz[2];
        sz[1]=sz[18],sz[2]=sz[20];
        sz[18]=sz[24],sz[20]=sz[23];
        sz[24]=sz[15],sz[23]=sz[13];
        sz[15]=a,sz[13]=b;
    }
    else
    {
        a = sz[9];
        sz[9] = sz[10],sz[10] = sz[12],sz[12] = sz[11],sz[11] = a;
        a = sz[1],b=sz[2];
        sz[1]=sz[15],sz[2]=sz[13];
        sz[15]=sz[24],sz[13]=sz[23];
        sz[24]=sz[18],sz[23]=sz[20];
        sz[18]=a,sz[20]=b;
    }
}
void change_4(int flag) //true为顺时针
{
    char a,b;
    if(flag)
    {
        a = sz[13];
        sz[13] = sz[15],sz[15] = sz[16],sz[16] = sz[14],sz[14] = a;
        a = sz[1],b=sz[3];
        sz[1]=sz[12],sz[3]=sz[10];
        sz[12]=sz[21],sz[10]=sz[23];
        sz[21]=sz[5],sz[23]=sz[7];
        sz[5]=a,sz[7]=b;
    }
    else
    {
        a = sz[13];
        sz[13] = sz[14],sz[14] = sz[16],sz[16] = sz[15],sz[15] = a;
        a = sz[1],b=sz[3];
        sz[1]=sz[5],sz[3]=sz[7];
        sz[5]=sz[21],sz[7]=sz[23];
        sz[21]=sz[12],sz[23]=sz[10];
        sz[12]=a,sz[10]=b;
    }
}
void change_5(int flag) //true为顺时针
{
    char a,b;
    if(flag)
    {
        a = sz[17];
        sz[17] = sz[19],sz[19] = sz[20],sz[20] = sz[18],sz[18] = a;
        a = sz[2],b=sz[4];
        sz[2]=sz[6],sz[4]=sz[8];
        sz[6]=sz[22],sz[8]=sz[24];
        sz[22]=sz[11],sz[24]=sz[9];
        sz[11]=a,sz[9]=b;
    }
    else
    {
        a = sz[17];
        sz[17] = sz[18],sz[18] = sz[20],sz[20] = sz[19],sz[19] = a;
        a = sz[2],b=sz[4];
        sz[2]=sz[11],sz[4]=sz[9];
        sz[11]=sz[22],sz[9]=sz[24];
        sz[22]=sz[6],sz[24]=sz[8];
        sz[6]=a,sz[8]=b;
    }
}
void change_6(int flag) //true为顺时针
{
    char a,b;
    if(flag)
    {
        a = sz[21];
        sz[21] = sz[23],sz[23] = sz[24],sz[24] = sz[22],sz[22] = a;
        a = sz[7],b=sz[8];
        sz[7]=sz[15],sz[8]=sz[16];
        sz[15]=sz[11],sz[16]=sz[12];
        sz[11]=sz[19],sz[12]=sz[20];
        sz[19]=a,sz[20]=b;
    }
    else
    {
        a = sz[21];
        sz[21] = sz[22],sz[22] = sz[24],sz[24] = sz[23],sz[23] = a;
        a = sz[7],b=sz[8];
        sz[7]=sz[19],sz[8]=sz[20];
        sz[19]=sz[11],sz[20]=sz[12];
        sz[11]=sz[15],sz[12]=sz[16];
        sz[15]=a,sz[16]=b;
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        init();
        scanf("%d %s",&n,str);
        for(int i=0;i<n;i++)
        {
            if(str[i]=='U') change_1(1);
            if(str[i]=='u') change_1(0);
            if(str[i]=='F') change_2(1);
            if(str[i]=='f') change_2(0);
            if(str[i]=='B') change_3(1);
            if(str[i]=='b') change_3(0);
            if(str[i]=='L') change_4(1);
            if(str[i]=='l') change_4(0);
            if(str[i]=='R') change_5(1);
            if(str[i]=='r') change_5(0);
            if(str[i]=='D') change_6(1);
            if(str[i]=='d') change_6(0);
        }
        printf("Case #%d: ",ca);
        for(int i=1;i<25;i++) printf("%c",sz[i]);
        printf("\n");
    }
    return 0;
}
