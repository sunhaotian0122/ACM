public class Main{
	public static void main(String[] argv) {
		CC17 rps = new CC17();
		for (int i = 0; i < 3000; i++) {
			int res = rps.rps(i);
			if (res == 100) break;
		}
	}
}
