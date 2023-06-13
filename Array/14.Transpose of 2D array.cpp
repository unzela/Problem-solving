#include <iostream>
#include <vector>
using namespace std;

void tranposeArray(vector<vector<int>> array,
                   vector<vector<int>> &array_transpose) {

  for (int i = 0; i < array.size(); i++) {
    for (int j = 0; j < array[i].size(); j++) {
      array_transpose[j][i] = array[i][j];
    }
  }
}

int main() {

  int rows;
  int columns;
  cout << "Enter number of rows" << endl;
  cin >> rows;
  cout << "Enter number of columns" << endl;
  cin >> columns;

  vector<vector<int>> array(rows, vector<int>(columns, 0));
  vector<vector<int>> array_transpose(rows, vector<int>(columns, 0));

  cout << "Enter the values" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cin >> array[i][j];
    }
  }

  tranposeArray(array, array_transpose);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << array_transpose[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
