#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <typeinfo>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

long long sz[100005],ans;

void MERGE(int left,int mid,int right)
{
    int n1=mid-left+1,n2=right-mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++) L[i]=sz[left+i];
    for(int i=0;i<n2;i++) R[i]=sz[mid+i+1];
    L[n1]=1000000000;
    R[n2]=1000000000;
    int i=0,j=0;
    for(int k=left;k<=right;k++)
    {
        if(L[i]<=R[j])
        {
            sz[k]=L[i];
            i++;
        }
        else
        {
            sz[k]=R[j];
            j++;
            ans+=(n1-i);
        }
    }
}

void merge_sort(int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        MERGE(left,mid,right);
    }
}

int main()
{
    int n;
    long long m;
    while(scanf("%d%lld",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d",&sz[i]);
        ans=0;
        merge_sort(0,n-1);
        if(m>ans) ans=0;
        else ans -= m;
        printf("%lld\n",ans);
    }
    return 0;
}
