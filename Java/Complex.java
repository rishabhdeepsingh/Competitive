package FastIO;

public class Complex {
    public double real;

    public double getImag() {
        return imag;
    }

    public void setImag(double imag) {
        this.imag = imag;
    }

    public double imag;

    public Complex() {
        this.real = 0;
        this.imag = 0;
    }

    public Complex(double real, double imaginary) {
        this.real = real;
        imag = imaginary;
    }

    public Complex(double real) {
        this.real = real;
        imag = 0;
    }

    public Complex scale(double o) {
        return new Complex(this.real * o, this.imag * o);
    }

    public double arg() {
        return Math.atan2(imag, real);
    }

    public Complex fromPolar(double r, double theta) {
        return new Complex(r * Math.cos(theta), r * Math.sin(theta));
    }

    public double absSquared() {
        return real * real + imag * imag;
    }

    public double abs() {
        return Math.sqrt(absSquared());
    }

    public Complex conj() {
        return new Complex(real, -imag);
    }

    public Complex add(Complex z) {
        return new Complex(real + z.real, imag + z.imag);
    }

    public Complex multiply(Complex w) {
        return new Complex(real * w.real - imag * w.imag, real * w.imag + imag * w.real);
    }

    public double mod() {
        if (real != 0 || imag != 0) {
            return Math.sqrt(real * real + imag * imag);
        } else {
            return 0d;
        }
    }

    public Complex sub(Complex o) {
        return new Complex(this.real - o.real, this.imag - o.imag);
    }

    public Complex div(Complex w) {
        double den = Math.pow(w.mod(), 2);
        return new Complex((real * w.real + imag * w.imag) / den, (imag * w.real - real * w.imag) / den);
    }

    public Complex exp() {
        return new Complex(Math.exp(real) * Math.cos(imag), Math.exp(real) * Math.sin(imag));
    }

    public Complex log() {
        return new Complex(Math.log(this.mod()), this.arg());
    }

    public Complex sqrt() {
        double r = Math.sqrt(this.mod());
        double theta = this.arg() / 2;
        return new Complex(r * Math.cos(theta), r * Math.sin(theta));
    }

    public double cosh(double theta) {
        return (Math.exp(theta) + Math.exp(-theta)) / 2;
    }

    public Complex cosh() {
        return new Complex(cosh(real) * Math.cos(imag), sinh(real) * Math.sin(imag));
    }

    public Complex cos() {
        return new Complex(cosh(imag) * Math.cos(real), -sinh(imag) * Math.sin(real));
    }

    private double sinh(double theta) {
        return (Math.exp(theta) - Math.exp(-theta)) / 2;
    }

    public Complex sinh() {
        return new Complex(sinh(real) * Math.cos(imag), cosh(real) * Math.sin(imag));
    }

    public Complex sin() {
        return new Complex(cosh(imag) * Math.sin(real), sinh(imag) * Math.cos(real));
    }

    public Complex tan() {
        return (this.sin()).div(this.cos());
    }

    public Complex inv() {
        double absSquared = absSquared();
        return new Complex(real / absSquared, -imag / absSquared);
    }

    public Complex divide(Complex o) {
        return this.multiply(o.inv());
    }

    @Override
    public String toString() {
        if (real != 0 && imag > 0) {
            return real + " + " + imag + "i";
        }
        if (real != 0 && imag < 0) {
            return real + " - " + (-imag) + "i";
        }
        if (imag == 0) {
            return String.valueOf(real);
        }
        if (real == 0) {
            return imag + "i";
        }
        return real + " + i*" + imag;

    }

    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (!(obj instanceof Complex)) {
            return false;
        }
        Complex other = (Complex) obj;
        if (real != other.real) {
            return false;
        }
        return !(imag != other.imag);
    }
}
