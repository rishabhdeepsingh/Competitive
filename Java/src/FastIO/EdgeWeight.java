package FastIO;

public class EdgeWeight {
    public long weight;
    public VertexWeight start;
    public VertexWeight target;

    public EdgeWeight(long weight, VertexWeight start, VertexWeight target) {
        this.weight = weight;
        this.start = start;
        this.target = target;
    }
}
