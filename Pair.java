package FastIO;

public class Pair implements Comparable<Pair> {

    public int x;
    public int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return (x + " " + y);
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) return false;
        Pair pairo = (Pair) o;
        return this.x == pairo.x &&
                this.y == pairo.y;
    }

    @Override
    public int compareTo(Pair p) {
        return Integer.compare(p.x, this.x);
    }
}
