#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

typedef std::vector<int> vi;

int partition2(vi &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vi &a, int low, int high, int &i, int &j){
  if (high - low <= 1)
  {
    if (a[high] < a[low])
      swap(a[high], a[low]);
    i = low;
    j = high;
    return;
  }

  int mid = low;
  int pivot = a[high];
  while (mid <= high)
  {
    if (a[mid]<pivot)
        swap(a[low++], a[mid++]);
    else if (a[mid]==pivot)
        mid++;
    else if (a[mid]>pivot)
        swap(a[mid], a[high--]);
  }
    //update i and j
    i = low-1;
    j = mid; //or high-1

}

void randomized_quick_sort(vi &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int i,j;
  partition3(a, l, r, i, j);

  randomized_quick_sort(a, l, i);
  randomized_quick_sort(a, j, r);
}

int main() {
  int n;
  std::cin >> n;
  vi a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
