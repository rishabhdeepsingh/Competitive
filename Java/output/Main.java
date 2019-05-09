import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Rishabhdeep Singh
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BellmenFord solver = new BellmenFord();
        solver.solve(1, in, out);
        out.close();
    }

    static class BellmenFord {
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

    static class EdgeWeight {
        public long weight;
        public VertexWeight start;
        public VertexWeight target;

        public EdgeWeight(long weight, VertexWeight start, VertexWeight target) {
            this.weight = weight;
            this.start = start;
            this.target = target;
        }

    }

    static class InputReader {
        private InputStream stream;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

    }

    static class VertexWeight implements Comparable<VertexWeight> {
        String name;
        public List<EdgeWeight> adjacencylist;
        public VertexWeight predecessor;
        public long distance = Long.MAX_VALUE;

        public VertexWeight(String name) {
            this.name = name;
            this.adjacencylist = new ArrayList<>();
        }

        public void setDistance(long distance) {
            this.distance = distance;
        }

        public void setPredecessor(VertexWeight predecessor) {
            this.predecessor = predecessor;
        }

        public int compareTo(VertexWeight o) {
            return Long.compare(this.distance, o.distance);
        }

        public String toString() {
            return name;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}

