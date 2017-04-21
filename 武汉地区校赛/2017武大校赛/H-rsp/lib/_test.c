#include <stdio.h>
#include "rps.h"

int seq[524288 * 2];
int seq_res[524288 * 2];
int pattern[480];
int next[480];

int main()
{
	int limit = 400;
	for (int i = 1; i < 524288 * 2; i++)
		seq[i] = ((long long) seq[i - 1] * 65973 + 28411) % 524288;
	for (int i = 0; i < 524288 * 2; i++)
		seq_res[i] = seq[i] % 3;
	for (int i = 0; i < 524288 * 2; i++)
		seq[i] = (3 - seq[i] % 3) % 3;
	for (int i = 0; i < 480; i++)
		pattern[i] = (cc17_rps(0) + 3) % 3;
	for (int i = 0; i < 524288; i++)
	{
		int flg = 1;
		for (int j = 0; j < 480 && flg; j++)
			flg = flg && (pattern[j] == seq[j + i]);
		if (flg)
		{
			for (int k = 0; k < 1500; k++)
			{
				int cur = i + 480 + k;
				int show = 0;
				if (seq_res[cur] == 0)
					show = 1;
				else if (seq_res[cur] == 1)
					show = 2;
				else if (seq_res[cur] == 2)
					show = 0;
				int res = cc17_rps(show);
				if (res == 100)
					return 0;
			}
		}
	}
	return 0;
}
