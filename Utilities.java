package FastIO;

import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

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

    void shuffleArray(int[] ar) {
        Random rnd = ThreadLocalRandom.current();
        for (int i = ar.length - 1; i > 0; i--) {
            int index = rnd.nextInt(i + 1);
            int a = ar[index];
            ar[index] = ar[i];
            ar[i] = a;
        }
    }

    int min(int... a) {
        int min = a[0];
        for (int i : a) min = Math.min(min, i);
        return min;
    }

    int max(int... a) {
        int max = a[0];
        for (int i : a) max = Math.max(max, i);
        return max;
    }

    int gcd(int... a) {
        int gcd = a[0];
        for (int i : a) gcd = gcd(gcd, i);
        return gcd;
    }

    long min(long... a) {
        long min = a[0];
        for (long i : a) min = Math.min(min, i);
        return min;
    }

    long max(long... a) {
        long max = a[0];
        for (long i : a) max = Math.max(max, i);
        return max;
    }

    long gcd(long... a) {
        long gcd = a[0];
        for (long i : a) gcd = gcd(gcd, i);
        return gcd;
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

    public static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    public static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static long mul(long x, long y, long mod) {
        return (x % mod) * (y % mod) % mod;
    }

    public static long power(long a, long k, long m) {
        long res = 1;
        while (k > 0) {
            if ((k & 1) != 0) {
                res = mul(res, a, m);
            }
            a = mul(a, a, m);
            k >>= 1;
        }
        return res;
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
