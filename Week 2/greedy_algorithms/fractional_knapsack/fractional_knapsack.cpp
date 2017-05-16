#include <iostream>
#include <vector>

using std::vector;
typedef vector<int> vi;

double get_optimal_value(int capacity, vi weights, vi values) {
  double value = 0.0;

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vi values(n);
  vi weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
