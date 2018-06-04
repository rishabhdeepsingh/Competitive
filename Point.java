package FastIO;

public class Point implements Comparable<Point> {
    public int x;    // x-coordinate
    public int y;    // y-coordinate

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return x + " " + y;
    }

    public boolean equals(Point obj) {
        return this.x == obj.x && this.y == obj.y;
    }

    @Override
    public int compareTo(Point o) {
        int c = Integer.compare(this.x, o.x);
        if (c != 0) {
            return c;
        }
        return Integer.compare(this.y, o.y);
    }
}
