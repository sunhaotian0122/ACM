#ifndef CC17_RPS
#define CC17_RPS

#include <stdio.h>

int _initalized = -1;
int _input_key = 0;
int _call_limit = 2000;
int _wincount = 0;
const char _accepted[] = "6d37d07307058f1d44d5dd89cb55060b6c2bf3a1";
const char _wronganswer[] = "WRONGANSWER";

int cc17_rps(int shape)
{
	int result = -1, computer_shape = -1;
	if (_call_limit == 0)
	{
		puts(_wronganswer);
		return 100;
	}
	_call_limit--;
	if (_initalized == -1) // not initaled
	{
		if (scanf("%d", &_initalized) != 1)
		{
			puts(_wronganswer);
			return 100;
		}
	}
	if (shape < 0 || shape > 2)
	{
		puts(_wronganswer);
		return 100;
	}
	_initalized = ((long long)_initalized * 65973 + 28411) % 524288;
	computer_shape = _initalized % 3;
	result = (shape - computer_shape + 3) % 3;
	if (result == 2)
	{
		_wincount = 0;
		return -1;
	}
	else if (result == 1)
	{
		_wincount++;
		if (_wincount == 1000)
		{
			puts(_accepted);
			return 100;
		}
		return 1;
	}
	else if (result == 0)
	{
		_wincount = 0;
		return 0;
	}
}

#endif
