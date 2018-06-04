package FastIO;

public class Pair<L, R> implements Comparable<Pair<L, R>> {

    public L x;
    public R y;

    public Pair(L x, R y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return (x + " " + y);
    }

    @Override
    public int hashCode() {
        return x.hashCode() ^ y.hashCode();
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) return false;
        Pair pairo = (Pair) o;
        return this.x.equals(pairo.x) &&
                this.y.equals(pairo.y);
    }

    @Override
    public int compareTo(Pair<L, R> o) {
        return 0;
    }
}
