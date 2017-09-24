import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigInteger a,b,ans;
        while(cin.hasNext())
        {
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            ans = a.multiply(b);
            System.out.println(ans);
        }
    }
}
