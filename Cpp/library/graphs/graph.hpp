template <typename T>
class graph {
public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  
  std::vector<edge> edges;
  std::vector<std::vector<int>> g;
  int n;
  int max_cost;
  
  graph(int _n) : n(_n) {
    g.resize(n);
  }
  
  virtual int add(int from, int to, T cost) = 0;
  
//  void add_directed(int from, int to, T cost = 1) {
//    g[from].push_back({from, to, cost});
//    max_cost = max(max_cost, cost);
//  }
};

//template <typename T>
//int graph<T>::add(int from, int to, T cost) {
//  add_directed(from, to, cost);
//  add_directed(to, from, cost);
//}