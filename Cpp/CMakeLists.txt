cmake_minimum_required(VERSION 3.14)
project(Cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++-10)

#ls -R library | awk '
#/:$/&&f{s=$0;f=0}
#/:$/&&!f{sub(/:$/,"");s=$0;f=1;next}
#NF&&f{ print s"/"$0 }'

file(GLOB HEADERS library/string/Z.hpp
        library/string/manacher.hpp
        library/collections/DSU.hpp
        library/collections/indexed_heap.hpp
        library/collections/ro_segtree.hpp
        library/collections/segment_tree.hpp
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
        library/number/Mint.hpp
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
        library/range/range.hpp
        library/range/rev_range.hpp
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
        library/Utils.hpp
        library/y_combinator.hpp
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
add_definitions(-Wlogical-op)
add_definitions(-fbounds-check)
add_definitions(-D_GLIBCXX_DEBUG)
add_definitions(-D_GLIBCXX_DEBUG_PEDANTIC)

