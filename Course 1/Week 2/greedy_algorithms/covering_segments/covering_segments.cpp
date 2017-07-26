#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int starting, ending;
};

typedef vector<Segment> v_seg;
typedef vector<int> vi;

bool cmp(Segment a, Segment b){
  int r1 = a.ending;
  int r2 = b.ending;
  return r1 < r2;
}

vi optimal_points(v_seg &segments) {
  vi points;
  //write your code here
  sort(segments.begin(), segments.end(), cmp); // sort the Segments based on the ending positions.

  int current = segments[0].ending;
  points.push_back(current);
  for(int i=0; i< segments.size(); i++) {
    if (current < segments[i].starting || current > segments[i].ending) {
      current = segments[i].ending;
      points.push_back(current);
    }
  }
return points;
}

int main() {
  int n;
  std::cin >> n;
  v_seg segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].starting >> segments[i].ending;
  }
  vi points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
