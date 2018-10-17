package FastIO;

public class FFTMultiply {
    static int n;
    // storing first polynomial, no of coefficients = order+1 hence size = order + 1
    static Complex[] p = new Complex[2 * n];

    // storing second polynomial, no of coefficients = order+1 hence size = order + 1
    static Complex[] q = new Complex[2 * n];

    //new Complex(Math.cos(Math.PI  / (noOfCoefficients)), Math.sin(Math.PI / (noOfCoefficients)));
    static Complex[] omega = new Complex[2 * n];

    //new Complex(Math.cos(Math.PI  / (noOfCoefficients)), -(Math.sin(Math.PI  / (noOfCoefficients))));
    static Complex[] omegaInverse = new Complex[2 * n];

    public FFTMultiply(int n) {
        this.n = n;
    }

    // splits the polynomial into two arrays based on odd and even indices
    public static Complex[] split(Complex[] a, int start) {
        Complex[] splitted = new Complex[a.length / 2];
        int i = 0;
        while (start < a.length) {
            splitted[i] = a[start];
            start += 2;
            i++;
        }
        return splitted;
    }

    public static Complex[] FFT(Complex[] a, int length, int pow) {
        if (length == 1) {
            return a;
        }

        Complex[] even = FFT(split(a, 0), length / 2, 2 * pow);
        Complex[] odd = FFT(split(a, 1), length / 2, 2 * pow);

        Complex[] f = new Complex[length];
        for (int i = 0; i < length; i++) {
            f[i] = new Complex();
        }
        // combining the solution
        for (int i = 0; i < length / 2; i++) {
            Complex temp = omega[i * pow].multiply(odd[i]);
            f[i] = even[i].add(temp);
            f[i + (length / 2)] = even[i].sub(temp);
        }
        return f;
    }
}
