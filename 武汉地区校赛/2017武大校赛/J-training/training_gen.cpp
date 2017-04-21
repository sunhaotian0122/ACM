#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	random_device rd;
	cout << n << endl;
	int maxsum = 1000;
	for (int i = 1; i <= n; i++)
	{
		int rand = rd() % min(500, maxsum - (n - i + 1) * 3) + 3;
		cout << rand << " \n"[i == n];
		maxsum -= rand;
	}
	return 0;
}
