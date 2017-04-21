import java.util.Scanner;

public class CC17 {
	static private long _input_key = 0,
			    _call_limit = 2000,
				_win_count = 0,
				_last_rand = 0;
	static private final String _accepted = "6d37d07307058f1d44d5dd89cb55060b6c2bf3a1";
	static private final String _wronganswer = "WRONGANSWER";
	static private Scanner scan = null;
	CC17() {
		scan = new Scanner(System.in);
		_last_rand = scan.nextInt();
	}
	int rps(int shape) {
		long result = 0;
		if (_call_limit == 0)
		{
			System.out.println(_wronganswer);
			return 100;
		}
		_call_limit--;
		if (shape < 0 || shape > 2)
		{
			System.out.println(_wronganswer);
			return 100;
		}
		_last_rand = (_last_rand * 65973 + 28411) % 524288;
		result = (shape - _last_rand % 3 + 3) % 3;
		if (result == 2)
		{
			_win_count = 0;
			return -1;
		} else if (result == 0)
		{
			_win_count = 0;
			return 0;
		} else if (result == 1)
		{
			_win_count++;
			if (_win_count == 1000)
			{
				System.out.println(_accepted);
				return 100;
			}
			return 1;
		}
		System.out.println(_wronganswer);
		return 100;
	}
}
