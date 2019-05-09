package Codes;

import FastIO.EdgeWeight;
import FastIO.InputReader;
import FastIO.OutputWriter;
import FastIO.VertexWeight;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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

    private void computePaths(VertexWeight source) {
        source.setDistance(0);
        PriorityQueue<VertexWeight> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(source);
        while (!priorityQueue.isEmpty()) {
            VertexWeight actualVertex = priorityQueue.poll();
            for (EdgeWeight edge : actualVertex.adjacencylist) {
                VertexWeight v = edge.target;
                long newDistance = actualVertex.distance + edge.weight;
                if (newDistance < v.distance) {
                    priorityQueue.remove(v);
                    v.setDistance(newDistance);
                    v.setPredecessor(actualVertex);
                    priorityQueue.add(v);
                }
            }
        }
    }

    private List<VertexWeight> getShortestPath(VertexWeight target) {
        List<VertexWeight> shortestpath = Stream.iterate(target, Objects::nonNull, vertex -> vertex.predecessor).collect(Collectors.toList());
        Collections.reverse(shortestpath);
        return shortestpath;
    }
}
