package FastIO;

public class Point {
    public long x;    // real-coordinate
    public long y;    // imag-coordinate

    public Point(long x, long y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return x + " " + y;
    }

    public boolean equals(Point obj) {
        return this.x == obj.x && this.y == obj.y;
    }
    //To sort them according to the Co-ordinate System
    //Comparator.comparingLong(a -> Math.abs(a[0]) + Math.abs(a[1]))

}
