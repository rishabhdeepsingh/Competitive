cmake_minimum_required(VERSION 3.14)
project(Cpp)
set(CMAKE_CXX_STANDARD 17)

#ls -R library | awk '
#/:$/&&f{s=$0;f=0}
#/:$/&&!f{sub(/:$/,"");s=$0;f=1;next}
#NF&&f{ print s"/"$0 }'

file(GLOB HEADERS library/Algo/Z.hpp
        library/Algo/manacher.hpp
        library/collections/DSU.hpp
        library/collections/arr.hpp
        library/collections/indexed_heap.hpp
        library/collections/mdarr.h
        library/collections/ro_segtree.hpp
        library/collections/segment_tree.hpp
        library/egor_graph/algo
        library/egor_graph/dfs_order.h
        library/egor_graph/edges
        library/egor_graph/graph.h
        library/egor_graph/hl_decomposition.h
        library/egor_graph/lca.h
        library/egor_graph/algo/centroid_decomposition.h
        library/egor_graph/algo/dijkstra.h
        library/egor_graph/algo/dinic.h
        library/egor_graph/algo/edge_distances.h
        library/egor_graph/algo/floyd_warshall.h
        library/egor_graph/algo/mincost_flow.h
        library/egor_graph/algo/strongly_connected.h
        library/egor_graph/algo/top_sort.h
        library/egor_graph/edges/base_edge.h
        library/egor_graph/edges/biedge.h
        library/egor_graph/edges/biweighted_edge.h
        library/egor_graph/edges/flow_edge.h
        library/egor_graph/edges/weighted_edge.h
        library/egor_graph/edges/weighted_flow_edge.h
        library/geometry/Circle.hpp
        library/geometry/Line.hpp
        library/geometry/Point.hpp
        library/geometry/Polygon.hpp
        library/geometry/Segment.hpp
        library/graphs/LCA.hpp
        library/graphs/dfs_forest.hpp
        library/graphs/digraph.hpp
        library/graphs/forest.hpp
        library/graphs/graph.hpp
        library/graphs/graph_functions.hpp
        library/graphs/hld_example.cpp
        library/graphs/hld_forest.hpp
        library/graphs/lca_forest.hpp
        library/graphs/ntt.hpp
        library/number/Modular.hpp
        library/number/Ncr.hpp
        library/number/Primes.hpp
        library/number/Rational.hpp
        library/number/Sieve.hpp
        library/number/bigint.hpp
        library/number/bigmod.hpp
        library/number/fft.hpp
        library/number/modulo.hpp
        library/number/multiplicative.hpp
        library/number/numbers.hpp
        library/number/phi.hpp
        library/number/prime_fft.hpp
        library/number/prime_tables.h
        library/number/primes5
        library/range/range.h
        library/range/rev_range.h
        library/trees/fenwick.hpp
        library/trees/fenwick2d.hpp
        library/trees/fenwick_range.hpp
        library/trees/lazysegtree.hpp
        library/trees/segtree.hpp
        library/trees/segtreemincount.hpp
        library/trees/segtreesum.hpp
        library/trees/segtreerangesum.hpp
        library/generators.hpp
        library/FUN.hpp
        )
add_executable(output output/main.cpp ${GLOB})
add_executable(testrunner testrunner/main.cpp)

# Don't change it
file(GLOB TASKS "tasks/*.cpp")
file(GLOB CONTESTS "contests/*.cpp")

file(GLOB HEADERS "library/*.hpp")

add_executable(test ${TASKS} ${HEADERS})

add_definitions(-DLOCAL)
add_definitions(-Wno-unused-result)
add_definitions(-Wshadow)
add_definitions(-Wall)
add_definitions(-fbounds-check)

