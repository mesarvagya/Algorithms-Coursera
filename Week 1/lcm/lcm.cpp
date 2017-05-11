#include <iostream>
typedef long long int lli;

// long long lcm_naive(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;

//   return (long long) a * b;
// }

lli gcd_efficient(lli num_one, lli num_two){
  if(num_two == 0)
    return num_one;
  else
    return gcd_efficient(num_two, num_one % num_two);
}

lli lcm_efficient(lli num_one, lli num_two){
	return (num_one * num_two) / gcd_efficient(num_one, num_two);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_efficient(a, b) << std::endl;
  return 0;
}
