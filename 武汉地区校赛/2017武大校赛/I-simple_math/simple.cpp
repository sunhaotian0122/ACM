/**************************************************************
    Problem: 2326
    User: EJQ
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:1276 kb
****************************************************************/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long N,MOD;
struct Mat{
    long long A[3][3];
}S[20],ans;
Mat operator * (Mat a,Mat b)
{
    Mat ret;
    ret.A[0][0]=(a.A[0][0]*b.A[0][0]+a.A[0][1]*b.A[1][0]+a.A[0][2]*b.A[2][0])%MOD;
    ret.A[0][1]=(a.A[0][0]*b.A[0][1]+a.A[0][1]*b.A[1][1]+a.A[0][2]*b.A[2][1])%MOD;
    ret.A[0][2]=(a.A[0][0]*b.A[0][2]+a.A[0][1]*b.A[1][2]+a.A[0][2]*b.A[2][2])%MOD;
     
    ret.A[1][0]=(a.A[1][0]*b.A[0][0]+a.A[1][1]*b.A[1][0]+a.A[1][2]*b.A[2][0])%MOD;
    ret.A[1][1]=(a.A[1][0]*b.A[0][1]+a.A[1][1]*b.A[1][1]+a.A[1][2]*b.A[2][1])%MOD;
    ret.A[1][2]=(a.A[1][0]*b.A[0][2]+a.A[1][1]*b.A[1][2]+a.A[1][2]*b.A[2][2])%MOD;
     
    ret.A[2][0]=(a.A[2][0]*b.A[0][0]+a.A[2][1]*b.A[1][0]+a.A[2][2]*b.A[2][0])%MOD;
    ret.A[2][1]=(a.A[2][0]*b.A[0][1]+a.A[2][1]*b.A[1][1]+a.A[2][2]*b.A[2][1])%MOD;
    ret.A[2][2]=(a.A[2][0]*b.A[0][2]+a.A[2][1]*b.A[1][2]+a.A[2][2]*b.A[2][2])%MOD;
    return ret;
}
void init()
{
    S[1].A[0][0]=10%MOD;
    S[1].A[1][0]=1;
    S[1].A[1][1]=1;
    S[1].A[2][0]=1;
    S[1].A[2][1]=1;
    S[1].A[2][2]=1;
    ans.A[0][0]=1;
    ans.A[1][1]=1;
    ans.A[2][2]=1;
    for (int i=2;i<20;i++)
    {
        S[i]=S[i-1];
        S[i].A[0][0]*=10;
        S[i].A[0][0]%=MOD;
    }
}
Mat Ksm(Mat a,long long k)
{
    Mat ret;
    ret.A[0][0]=ret.A[1][1]=ret.A[2][2]=1;
    if (k==0)
        return ret;
    if (k==1)
        return a;
    if (k%2==0)
    {
        ret=Ksm(a,k/2);
        return ret*ret;
    }else
    {
        ret=Ksm(a,k-1);
        return ret*a;
    }
}
int main()
{
    long long begin=1,i,nn,len=0,k=1;
	MOD = 11;
    scanf("%lld",&N);
    init();
    nn=N;
    while (nn)
    {
        nn/=10;
        len++;
    }
    for (i=1;i<len;i++)
    {
        ans=ans*Ksm(S[i],k*9);
        k*=10;
    }
    //cerr<<k<<"-"<<len<<endl;
    ans=ans*Ksm(S[len],N-k+1);
    printf("%lld\n",ans.A[2][0]);
    return 0;
}
