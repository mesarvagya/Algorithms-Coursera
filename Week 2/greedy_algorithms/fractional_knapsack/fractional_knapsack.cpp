#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
typedef vector<int> vi;

typedef struct item {
    int weight, value;
} Item;

typedef std::vector<Item> v_item;

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double get_optimal_value(int capacity, v_item items, int n)
{
    double value = 0.0;
    // write your code here
    sort(items.begin(), items.end(), cmp); // each item is now sorted on the basis of value per weight.

    for (int i = 0; i < items.size(); ++i) {
        if (capacity == 0)
            return value;
        else {
            int actual = std::min(items[i].weight, capacity);
            value += actual * ((double)items[i].value / items[i].weight);
            items[i].weight -= actual;
            capacity -= actual;
        }
    }
    return value;
}

int main()
{
    int n;
    int capacity;
    std::cin >> n >> capacity;
    v_item items;
    for (int i = 0; i < n; i++) {
        Item it;
        std::cin >> it.value >> it.weight;
        items.push_back(it);
    }

    double optimal_value = get_optimal_value(capacity, items, n);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
