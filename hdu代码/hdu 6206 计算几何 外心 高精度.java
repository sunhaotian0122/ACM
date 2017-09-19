import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    private static final BigDecimal two = new BigDecimal(2.0);

    static class Point{
        public BigDecimal x,y;

        public Point(){}
        public Point(BigDecimal _x,BigDecimal _y){
            x = _x;
            y = _y;
        }
    }

    private static Point circumcenter(Point a,Point b,Point c)
    {
        BigDecimal a1,a2,b1,b2,c1,c2,ox,oy;

        a1 = two.multiply(b.x.subtract(a.x));
        b1 = two.multiply(b.y.subtract(a.y));
        c1 = b.x.multiply(b.x).add(b.y.multiply(b.y)).subtract(a.x.multiply(a.x)).subtract(a.y.multiply(a.y));
        a2 = two.multiply(c.x.subtract(b.x));
        b2 = two.multiply(c.y.subtract(b.y));
        c2 = c.x.multiply(c.x).add(c.y.multiply(c.y)).subtract(b.x.multiply(b.x)).subtract(b.y.multiply(b.y));

        ox = c1.multiply(b2).subtract(c2.multiply(b1)).divide(a1.multiply(b2).subtract(a2.multiply(b1)));
        oy = a1.multiply(c2).subtract(a2.multiply(c1)).divide(a1.multiply(b2).subtract(a2.multiply(b1)));

        return new Point(ox,oy);
    }

    private static BigDecimal dis(Point a,Point b)
    {
        return a.x.subtract(b.x).multiply(a.x.subtract(b.x)).add(a.y.subtract(b.y).multiply(a.y.subtract(b.y)));
    }

    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        Point A,B,C,D,O;
        A = new Point();
        B = new Point();
        C = new Point();
        D = new Point();
        int t = cin.nextInt();
        while(t-- > 0)
        {
            A.x = cin.nextBigDecimal();
            A.y = cin.nextBigDecimal();
            B.x = cin.nextBigDecimal();
            B.y = cin.nextBigDecimal();
            C.x = cin.nextBigDecimal();
            C.y = cin.nextBigDecimal();
            D.x = cin.nextBigDecimal();
            D.y = cin.nextBigDecimal();

            O = circumcenter(A,B,C);

            BigDecimal OA = dis(O,A);
            BigDecimal OD = dis(O,D);

            if(OD.compareTo(OA)>0)
                System.out.println("Accepted");
            else
                System.out.println("Rejected");
        }
    }
}
