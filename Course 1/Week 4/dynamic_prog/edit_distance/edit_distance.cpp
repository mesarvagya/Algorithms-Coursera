#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

int edit_distance(const string &str1, const string &str2) {
    //write your code here
    int row = str1.length() + 1;
    int col = str2.length() + 1;
    
    vvi matrix;
    for(int i = 0; i < row; ++i){
        vi temp_row;
        for(int j=0; j < col; ++j){
            temp_row.push_back(0);
        }
        matrix.push_back(temp_row);
    }
    
    for(int i=0; i<col; ++i){
        matrix[0][i] = i;
    }
    
    for(int i=0; i<row; ++i){
        matrix[i][0] = i;
    }
    
    std::string str1_new = "0" + str1;
    std::string str2_new = "0" + str2;
    for(int j=1; j<col; ++j){
        for(int i=1; i < row; ++i){
            int insertion = matrix[i][j-1] + 1;
            int deletion = matrix[i-1][j] + 1;
            int match = matrix[i-1][j-1];
            int mismatch = matrix[i-1][j-1] + 1;
            if(str1_new[i] == str2_new[j])
                matrix[i][j] = std::min({insertion, deletion,match});
            else
                matrix[i][j] = std::min({insertion, deletion,mismatch});
        }
    }
    return matrix[row-1][col-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
