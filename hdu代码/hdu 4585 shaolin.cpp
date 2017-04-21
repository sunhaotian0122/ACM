#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 5e6 + 5;
int ans[maxn];
set<int>power;

int solve(int x)
{
	int tmp;
	set<int>::iterator l,h;
	l = power.lower_bound(x);
	h = power.upper_bound(x);
	if (l == power.begin())
	{
		return *h;
	}
	else
	{
		l--;
		tmp = x - *l;
		if (*h - x >= tmp) return *l;
		else return *h;
	}

}

int main()
{
	int n,a,b;
	while (~scanf("%d", &n) && n)
	{
		power.clear();
		power.insert(1000000000);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a, &b);
			ans[b] = a;
			power.insert(b);
			if(solve(b)==1000000000) printf("%d 1\n",a);
			else printf("%d %d\n",a,ans[solve(b)]);
		}
	}
	return 0;
}
