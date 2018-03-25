package FastIO;

public class Utilities {
    public static String repeat(int count, String with) {
        return new String(new char[count]).replace("\0", with);
    }

    public static boolean isPalindrome(String str) {
        return str.equals(new StringBuilder(str).reverse().toString());
    }

    public static long polygonArea(long[][] shape, int n) {
        long area = 0;
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            area += (shape[j][0] + shape[i][0]) * (shape[j][1] - shape[i][1]);
            j = i;
        }
        return area / 2;
    }

    public static double polygonArea(double X[], double Y[], int n) {
        double area = 0.0;
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            area += (X[j] + X[i]) * (Y[j] - Y[i]);
            j = i;
        }
        return Math.abs(area / 2.0);
    }

    public static double polygonArea(java.awt.Point a, java.awt.Point b, java.awt.Point c) {
        double[] _X = {a.x, b.x, c.x};
        double[] _Y = {a.y, b.y, c.y};
        return polygonArea(_X, _Y, 3);
    }

    public static long modInverse(long a, long m) {
        return power(a, m - 2, m);
    }

    public static boolean onLine(Point[] shape, Point p) {
        for (int i = 0; i < shape.length; i++) {
            float x1 = shape[i].x;
            float y1 = shape[i].y;
            float x2 = shape[(i + 1) % shape.length].x;
            float y2 = shape[(i + 1) % shape.length].y;
            float x = p.x, y = p.y;
            if ((x - x1) / (x2 - x1) == (y - y1) / (y2 - y1))
                return true;
        }
        return false;
    }

    public static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static long power(long x, long y, long m) {
        if (y == 0)
            return 1;
        long p = power(x, y / 2, m) % m;
        p = (p * p) % m;
        if (y % 2 == 0)
            return p;
        else
            return (x * p) % m;
    }
}
