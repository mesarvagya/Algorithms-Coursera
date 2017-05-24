#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
typedef std::vector<int> vi;

int binary_search(const vi &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  int mid;
  while(left <= right){
    mid = (int)(left + right)/2;
    if(a[mid] == x)
      return mid;
    else if(a[mid] > x)
      right = mid-1;
    else if(a[mid] < x)
      left = mid + 1;
  }
  return -1;
}

int linear_search(const vi &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vi a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vi b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
