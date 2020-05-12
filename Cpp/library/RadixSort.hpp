#include "./IO.hpp"

template<typename T>
class RadixSort {
public:
  RadixSort() = default;
  
  void sort(vector<T> &arr) {
    T m = *max_element(arr.begin(), arr.end());
    for (int exp = 1; m / exp > 0; exp *= 10)
      countSort(arr, exp);
  }

private:
  
  void countSort(vector<T> &arr, int exp) {
    int n = arr.size();
    vector<T> output(n, 0), count(10, 0);
    
    for (int i = 0; i < n; i++)
      count[(arr[i] / exp) % 10]++;
    
    for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++)
      arr[i] = output[i];
  }
};