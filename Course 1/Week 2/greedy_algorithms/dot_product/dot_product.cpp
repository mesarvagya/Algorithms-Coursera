#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
typedef std::vector<int> vi;
typedef long long int lli;

lli max_dot_product(vi a, vi b) {
  // write your code here
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  lli result = 0;


  for( int i = 0; i < a.size(); ++i){
    result += (lli) a[i] * (lli) b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vi a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
