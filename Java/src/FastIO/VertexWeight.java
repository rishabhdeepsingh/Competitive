package FastIO;

import java.util.ArrayList;
import java.util.List;

public class VertexWeight implements Comparable<VertexWeight> {
    String name;
    public List<EdgeWeight> adjacencylist;
    boolean visited;
    public VertexWeight predecessor;
    public long distance = Long.MAX_VALUE;

    public VertexWeight(String name) {
        this.name = name;
        this.adjacencylist = new ArrayList<>();
    }

    public void addNeighbour(EdgeWeight edge) {
        this.adjacencylist.add(edge);
    }

    public void setDistance(long distance) {
        this.distance = distance;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    public void setPredecessor(VertexWeight predecessor) {
        this.predecessor = predecessor;
    }

    @Override
    public int compareTo(VertexWeight o) {
        return Long.compare(this.distance, o.distance);
    }

    @Override
    public String toString() {
        return name;
    }

}

