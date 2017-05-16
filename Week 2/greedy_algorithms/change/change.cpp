#include <iostream>


// coin denominations are 1,5,10
int get_change(int m) {
  //write your code here
    if(m < 5)
        // if coin is less than 5, we need same # of 1-coins.
        return m;
    else if(m == 5) 
        // if its 5, handle a single 5-coin
        return 1;
    else if(m > 5 && m < 10) 
        // if its greater than 5 but less than 10, handle a single 5-coin and make change for (total - 5)
        return 1 + get_change(m - 5);
    else if(m  == 10) 
        // if its 10 handle a single 10-coin
        return 1;
    else 
        // if its greater than 10, handle a single 10-coin and make change for (total - 10)
        return 1 + get_change(m-10);
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
