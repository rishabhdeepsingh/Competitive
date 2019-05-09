package FastIO;

public class Coordinate {
    public long x, y, z;

    public Coordinate(long x, long y, long z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Coordinate diff(Coordinate o1) {
        return new Coordinate(this.x - o1.x, this.y - o1.y, this.z - o1.z);
    }

    public double dis(Coordinate o1) {
        return Math.sqrt((this.x - o1.x) * (this.x - o1.x) + (this.y - o1.y) * (this.y - o1.y) + (this.z - o1.z) * (this.z - o1.z));
    }
}
