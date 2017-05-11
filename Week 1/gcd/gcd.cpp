#include <iostream>

typedef long long int lli;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

lli gcd_efficient(lli num_one, lli num_two){
  if(num_two == 0)
    return num_one;
  else
    return gcd_efficient(num_two, num_one % num_two);
}


int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_efficient(a,b) << std::endl;
  return 0;
}
