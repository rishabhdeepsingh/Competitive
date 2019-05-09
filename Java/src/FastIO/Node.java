package FastIO;

import java.util.ArrayList;
import java.util.List;

public class Node {
    List<Integer> neighbors;

    Node() {
        neighbors = new ArrayList<>();
    }

    void addEdge(Integer v) {
        neighbors.add(v);
    }

    public List<Integer> getNeighbors() {
        return neighbors;
    }
}
