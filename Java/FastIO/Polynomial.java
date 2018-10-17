package FastIO;

public class Polynomial {

    public static Complex[] FFT(Complex[] x) {
        int n = x.length;
        // base case
        if (n == 1) return new Complex[]{x[0]};
        // radix 2 Cooley-Tukey FFT
        if (n % 2 != 0) {
            throw new IllegalArgumentException("n is not a power of 2");
        }
        // FFT of even terms
        Complex[] even = new Complex[n / 2];
        for (int k = 0; k < n / 2; k++) {
            even[k] = x[2 * k];
        }
        Complex[] q = FFT(even);
        // FFT of odd terms
        Complex[] odd = even;  // reuse the array
        for (int k = 0; k < n / 2; k++) {
            odd[k] = x[2 * k + 1];
        }
        Complex[] r = FFT(odd);
        // combine
        Complex[] y = new Complex[n];
        for (int k = 0; k < n / 2; k++) {
            double theta = (-2 * k * Math.PI) / n;
            Complex wk = new Complex(Math.cos(theta), Math.sin(theta));
            y[k] = q[k].add(wk.multiply(r[k]));
            y[k + n / 2] = q[k].sub(wk.multiply(r[k]));
        }
        return y;
    }

    // compute the inverse FFT of x[], assuming its length is a power of 2
    public static Complex[] ifft(Complex[] x) {
        int n = x.length;
        Complex[] y = new Complex[n];

        // take conjugate
        for (int i = 0; i < n; i++) {
            y[i] = x[i].conj();
        }

        // compute forward FFT
        y = FFT(y);

        // take conjugate again
        for (int i = 0; i < n; i++) {
            y[i] = y[i].conj();
        }

        // divide by n
        for (int i = 0; i < n; i++) {
            y[i] = y[i].scale(1.0 / n);
        }
        return y;
    }

    // compute the circular convolution of x and y
    public static Complex[] cconvolve(Complex[] x, Complex[] y) {
        // should probably pad x and y with 0s so that they have same length
        // and are powers of 2
        if (x.length != y.length) {
            throw new IllegalArgumentException("Dimensions don't agree");
        }
        int n = x.length;
        // compute FFT of each sequence
        Complex[] a = FFT(x);
        Complex[] b = FFT(y);

        // point-wise multiply
        Complex[] c = new Complex[n];
        for (int i = 0; i < n; i++) {
            c[i] = a[i].multiply(b[i]);
        }

        // compute inverse FFT
        return ifft(c);
    }

    // compute the linear convolution of x and y
    public static Complex[] convolve(Complex[] x, Complex[] y) {
        Complex ZERO = new Complex(0, 0);
        Complex[] a = new Complex[2 * x.length];
        for (int i = 0; i < x.length; i++) a[i] = x[i];
        for (int i = x.length; i < 2 * x.length; i++) a[i] = ZERO;

        Complex[] b = new Complex[2 * y.length];
        for (int i = 0; i < y.length; i++) b[i] = y[i];
        for (int i = y.length; i < 2 * y.length; i++) b[i] = ZERO;
        return cconvolve(a, b);
    }
}
