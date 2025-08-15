#include "../IO.hpp"

template <class T>
class CoordicateCompression {
  vector<T> indices;

 public:
  explicit CoordicateCompression() = default;
  
  explicit CoordicateCompression(vector<T> v) : indices(v) {
    init();
  }

  void add(T value) {
    indices.push_back(value);
  }

  void init() {
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
  }

  int getId(T value) {
    return lower_bound(indices.begin(), indices.end(), value) - indices.begin();
  }

  const T& operator[](int id) {
    return indices[id];
  }

  auto size() {
    return indices.size();
  }
};