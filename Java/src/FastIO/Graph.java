package FastIO;

import java.util.ArrayList;
import java.util.List;

public class Graph {
    List<Node> nodes = new ArrayList<>();

    public Graph(int n) {
        for (int i = 0; i < n; ++i) {
            nodes.add(new Node());
        }
    }

    public Node getNode(int v) {
        return nodes.get(v);
    }

    public void addEdge(int u, int v) {
        getNode(u).addEdge(v);
        getNode(v).addEdge(u);
    }
}