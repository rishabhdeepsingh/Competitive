package FastIO;

public class Complex {
    public double x, y;

    public Complex(double real, double imaginary) {
        x = real;
        y = imaginary;
    }

    public Complex(double real) {
        x = real;
        y = 0;
    }

    public double arg() {
        return Math.atan2(y, x);
    }

    public Complex fromPolar(double r, double theta) {
        return new Complex(r * Math.cos(theta), r * Math.sin(theta));
    }

    public double absSquared() {
        return x * x + y * y;
    }

    public double abs() {
        return Math.sqrt(absSquared());
    }

    public Complex conj() {
        return new Complex(x, -y);
    }

    public Complex add(Complex z) {
        return new Complex(x + z.x, y + z.y);
    }

    public Complex multiply(Complex w) {
        return new Complex(x * w.x - y * w.y, x * w.y + y * w.x);
    }

    public double mod() {
        if (x != 0 || y != 0) {
            return Math.sqrt(x * x + y * y);
        } else {
            return 0d;
        }
    }

    public Complex div(Complex w) {
        double den = Math.pow(w.mod(), 2);
        return new Complex((x * w.x + y * w.y) / den, (y * w.x - x * w.y) / den);
    }

    public Complex exp() {
        return new Complex(Math.exp(x) * Math.cos(y), Math.exp(x) * Math.sin(y));
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
        return new Complex(cosh(x) * Math.cos(y), sinh(x) * Math.sin(y));
    }

    public Complex cos() {
        return new Complex(cosh(y) * Math.cos(x), -sinh(y) * Math.sin(x));
    }

    private double sinh(double theta) {
        return (Math.exp(theta) - Math.exp(-theta)) / 2;
    }

    public Complex sinh() {
        return new Complex(sinh(x) * Math.cos(y), cosh(x) * Math.sin(y));
    }

    public Complex sin() {
        return new Complex(cosh(y) * Math.sin(x), sinh(y) * Math.cos(x));
    }

    public Complex tan() {
        return (this.sin()).div(this.cos());
    }

    public Complex inv() {
        double abs_squared = absSquared();
        return new Complex(x / abs_squared, -y / abs_squared);
    }

    @Override
    public String toString() {
        if (x != 0 && y > 0) {
            return x + " + " + y + "i";
        }
        if (x != 0 && y < 0) {
            return x + " - " + (-y) + "i";
        }
        if (y == 0) {
            return String.valueOf(x);
        }
        if (x == 0) {
            return y + "i";
        }
        // shouldn't get here (unless Inf or NaN)
        return x + " + i*" + y;

    }

    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (!(obj instanceof Complex)) {
            return false;
        }
        Complex other = (Complex) obj;
        if (x != other.x) {
            return false;
        }
        return !(y != other.y);
    }
}
