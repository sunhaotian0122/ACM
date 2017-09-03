#include <bits/stdc++.h>
using namespace std;
const int maxn = 125250 + 100;
int m, n;
int b[maxn];
int a[maxn];
struct node{
    int x;
    bool operator <(const node &res) const {
        return x < res.x;
    }
};
multiset<int> s;
multiset<int>::iterator it;
map<int, int> mp;
int main()
{
    mp.clear();
    for(int i = 1; i <= 501; i++)
    {
        int x = i * (i + 1) / 2;
        mp[x] = i;
    }
    while(~scanf("%d", &m))
    {
        s.clear();
        n = mp[m];
        int ans;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &b[i]);
            ans = b[i];
            s.insert(ans);
        }
        if(n == 1)
        {
            printf("1\n");
            printf("%d\n", b[1]);
            continue;
        }
        if(m == 0)
        {
            printf("0\n");
            continue;
        }
        sort(b + 1, b + m + 1);
        int cnt = 0;
        a[++cnt] = b[1];
        a[++cnt] = b[2];
        it = s.find(b[1]);
        s.erase(it);
        it = s.find(b[2]);
        s.erase(it);
        int test;
        while(cnt < n)
        {
            for(int j = 1; j < cnt; j++)
            {
                test = a[j] + a[cnt];
                //cout<<"test == "<<test<<endl;
                it = s.find(test);
                s.erase(it);
            }
            it = s.begin();
            a[++cnt] = *it;
            s.erase(it);
        }
        sort(a + 1, a + n + 1);
        printf("%d\n", n);
        for(int i = 1; i <= n; i++)
        {
            if(i == n)
            {
                printf("%d\n", a[i]);
            }
            else printf("%d ", a[i]);
        }
    }
    return 0;
}
