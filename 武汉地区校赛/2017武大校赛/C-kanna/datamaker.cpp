#include <bits/stdc++.h>
using namespace std;
const int N = 2010, mod = 1e8, mod2 = 1e6;
short used[mod * 3 + 10];
int main()
{
	//freopen("5.in", "w", stdout);
	srand(time(0));
	int n = 2e3;
	printf("%d\n", n);
	int xx, yy, rr, ww;
	for(int i = 1; i <= n; ++i)
	{
		bool flag = 1;
		while(flag)
		{
			yy = rand() % mod + 1;
			if(used[yy + mod] == 2 || used[yy - 1 + mod] == 2)
				continue;
			rr = rand() % mod + 1;
			while(flag)
			{
				flag = 0;
				for(int j = yy - rr; j < yy + rr; ++j)
					if(used[j + mod] == 2)
					{
						flag = 1;
						break;
					}
				if(flag)
					rr = rand() % (rr - 1) + 1;
			}
		}
		for(int j = yy - rr; j < yy + rr; ++j)
			++used[j + mod];
		xx = rand() % mod + 1;
		ww = rand() % mod2 + 1;
		printf("%d %d %d %d\n", xx, yy, rr, ww);
	}
	return 0;
}
