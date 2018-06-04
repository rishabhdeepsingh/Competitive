package FastIO;

import java.math.BigInteger;

public class Maths {
    public final long MOD = (long) 1e9 + 7;
    public long[] fact = generateFactorials(1000000);
    public long[] invFact = generateReverseFactorials(1000000);

    public static long modInverse(long a, long m) {
        return power(a, m - 2, m);
    }

    public static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static long power(long a, long k, long m) {
        long res = 1;
        while (k > 0) {
            if ((k & 1) != 0) {
                res = res * a % m;
            }
            a = a * a % m;
            k >>= 1;
        }
        return res;
    }

    public long comb(final int m, final int n) {
        return (((fact[n] * invFact[m]) % MOD) * invFact[n - m]) % MOD;
    }

    public long[] generateFactorials(int count) {
        long[] result = new long[count];
        result[0] = 1;
        for (int i = 1; i < count; i++) {
            result[i] = (result[i - 1] * i) % MOD;
        }
        return result;
    }

    long[] generateReverseFactorials(int upTo) {
        final long[] reverseFactorials = new long[upTo];
        reverseFactorials[0] = reverseFactorials[1] = 1;
        final BigInteger BIG_MOD = BigInteger.valueOf(MOD);
        for (int i = 1; i < upTo; i++) {
            reverseFactorials[i] = (BigInteger.valueOf(i).modInverse(BIG_MOD).longValue() * reverseFactorials[i - 1]) % MOD;
        }
        return reverseFactorials;
    }
}
