package Codes;

import FastIO.EdgeWeight;
import FastIO.InputReader;
import FastIO.OutputWriter;
import FastIO.VertexWeight;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class BellmenFord {
    List<EdgeWeight> edgeList;
    List<VertexWeight> vertexList;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        edgeList = new ArrayList<>();
        vertexList = new ArrayList<>();
        vertexList.add(new VertexWeight("A"));
        vertexList.add(new VertexWeight("B"));
        vertexList.add(new VertexWeight("C"));
        edgeList.add(new EdgeWeight(1, vertexList.get(0), vertexList.get(1)));
        edgeList.add(new EdgeWeight(1, vertexList.get(0), vertexList.get(2)));
        edgeList.add(new EdgeWeight(1, vertexList.get(1), vertexList.get(1)));
        bellmenFord(vertexList.get(0));
        out.println(shortestPath(vertexList.get(2)));
    }

    void bellmenFord(VertexWeight source) {
        source.setDistance(0);
        for (int i = 0; i < vertexList.size(); i++) {
            for (EdgeWeight edge : edgeList) {
                VertexWeight u = edge.start;
                VertexWeight v = edge.target;
                if (u.distance == Long.MAX_VALUE) continue;
                long newDistance = u.distance + edge.weight;
                if (newDistance < v.distance) {
                    v.setDistance(newDistance);
                    v.setPredecessor(u);
                }
            }
        }
        for (EdgeWeight edge : edgeList) {
            if (edge.start.distance != Long.MAX_VALUE) {
                if (hasCycle(edge)) {
                    return;
                }
            }
        }
    }

    private List<VertexWeight> shortestPath(VertexWeight target) {
        if (target.distance == Long.MAX_VALUE) {
            return new ArrayList<>();
            // No Path from source to target
        }
        List<VertexWeight> shortestpath = Stream.iterate(target, Objects::nonNull, vertex -> vertex.predecessor).collect(Collectors.toList());
        Collections.reverse(shortestpath);
        return shortestpath;
    }

    private boolean hasCycle(EdgeWeight edge) {
        return edge.start.distance + edge.weight < edge.target.distance;
    }
}
