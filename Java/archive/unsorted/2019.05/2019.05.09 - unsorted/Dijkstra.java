package Codes;

import FastIO.InputReader;
import FastIO.OutputWriter;
import FastIO.VertexWeight;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Dijkstra {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        VertexWeight v0 = new VertexWeight("A");
        VertexWeight v1 = new VertexWeight("B");
        VertexWeight v2 = new VertexWeight("C");
        v0.addNeighbour(new EdgeWeight(1l, v0, v1));
        v0.addNeighbour(new EdgeWeight(3l, v0, v2));
        v1.addNeighbour(new EdgeWeight(1l, v1, v2));
        computePaths(v0);
        out.println(getShortestPath(v2));
    }

    public static void computePaths(VertexWeight source) {
        source.distance = 0;
        PriorityQueue<VertexWeight> priorityQueue =  new PriorityQueue<>();
        priorityQueue.add(source);
        while (!priorityQueue.isEmpty()) {
            VertexWeight actualVertex = priorityQueue.poll();
            for (EdgeWeight edge : actualVertex.adjacencylist) {
                VertexWeight v = edge.target;
                long newDistace = actualVertex.distance + edge.weight;
                if (newDistace < v.distance) {
                    priorityQueue.remove(v);
                    v.distance = newDistace;
                    v.predecessor = actualVertex;
                    priorityQueue.add(v);
                }
            }
        }
    }

    public List<VertexWeight> getShortestPath(VertexWeight target) {
        List<VertexWeight> shortestpath = new ArrayList<>();
        for (VertexWeight vertex = target; vertex != null; vertex = vertex.predecessor) {
            shortestpath.add(vertex);
        }
        Collections.reverse(shortestpath);
        return shortestpath;
    }
}
