package FastIO;

public class Utilities {
    public static int Gcd(int a, int b) {
        if (a == 0)
            return b;
        else
            return Gcd(b % a, a);
    }
    public static long Gcd(long a, long b) {
        if (a == 0)
            return b;
        else
            return Gcd(b % a, a);
    }

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



    public static boolean isPrime(int num) {
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
}
