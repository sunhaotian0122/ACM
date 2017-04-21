#include <stdio.h>
#include "rps.h"

int main()
{
	for (int i = 0; i < 3000; i++) {
		int res = cc17_rps(i);
		if (res == 100) {
			break;
		}
	}
	return 0;
}
