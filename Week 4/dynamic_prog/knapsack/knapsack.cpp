#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int optimal_weight(int W, const vi &w) {
  //write your code here

  //create a matrix of size (W+1) * (sizeof(weights vector) + 1) (Row by column)
  vvi matrix;
  int size = w.size();
  for(int i = 0; i < w.size(); ++i){
    vi temp_row;
    for(int j = 0; j <= W; ++j){
      temp_row.push_back(0);
    }
    matrix.push_back(temp_row);
  }

  for(int i=1; i < w.size(); ++i){
    for(int j=1; j <= W; ++j){
      if(j-w[i] < 0)
        matrix[i][j] = matrix[i-1][j];
      else
        matrix[i][j] = std::max(matrix[i-1][j], w[i] + matrix[i-1][j-w[i]]);
    }
  }

  return matrix[w.size()-1][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vi w(n+1);
  w.push_back(0);
  for (int i = 1; i <= n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
