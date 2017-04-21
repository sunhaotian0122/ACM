public class Main{
	public static void main(String[] argv) {
		long[] seq = new long[524288 * 2];
		long[] seq_res = new long[524288 * 2];
		long[] pattern = new long[524288 * 2];
		CC17 rps = new CC17();
		seq[0] = 0;
		for (int i = 1; i < 524288 * 2; i++)
			seq[i] = (seq[i - 1] * 65973 + 28411) % 524288;
		for (int i = 0; i < 524288 * 2; i++)
			seq_res[i] = seq[i] % 3;
		for (int i = 0; i < 524288 * 2; i++)
			seq[i] = (3 - seq[i] % 3) % 3;
		for (int i = 0; i < 480; i++)
			pattern[i] = (rps.rps(0) + 3) % 3;
		for (int i = 0; i < 524288; i++)
		{
			boolean flg = true;
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
					int res = rps.rps(show);
					if (res == 100)
						System.exit(0);
				}
			}
		}
	}
}
