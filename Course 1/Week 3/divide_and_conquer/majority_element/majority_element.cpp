#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
typedef std::vector<int> vi;

int count_occurence(vi &a, int majority){
  int count = 0;
  for(auto item: a){
    if(item == majority)
      ++count;
  }
  return count;
}

int get_majority_element(vi &a, int left, int right) {
  if (left > right) return -1;
  if(left == right) return a[left];
  int mid = (int) (left+right)/2;

  int majority_lower_half = get_majority_element(a, left, mid);
  int majority_higher_half = get_majority_element(a, mid+1, right);

  if(majority_higher_half == majority_lower_half)
    return majority_lower_half;

  count_lower = count_occurence(a,majority_lower_half);
  count_higher = count_occurence(a,majority_higher_half);

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vi a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
