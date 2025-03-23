#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rows, cols, cube;
            for (int j = 0; j < 9; ++j) {
                // Check row
                if (board[i][j] != '.' && !rows.insert(board[i][j]).second) {
                    return false;
                }
                // Check column
                if (board[j][i] != '.' && !cols.insert(board[j][i]).second) {
                    return false;
                }
                // Check 3x3 sub-box
                int rowIndex = 3 * (i / 3) + j / 3;
                int colIndex = 3 * (i % 3) + j % 3;
                if (board[rowIndex][colIndex] != '.' && !cube.insert(board[rowIndex][colIndex]).second) {
                    return false;
                }
            }
        }
        return true; // Ensure a return value is provided
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    string input;
    cout << "Ingrese el tablero de Sudoku en el formato de las imágenes:" << endl;
    getline(cin, input);

    stringstream ss(input);
    char c;
    int i = 0, j = 0;

    while (ss >> c) {
        if (c == '[' || c == ']' || c == ',') continue;
        if (c == '"') continue;
        board[i][j] = c;
        j++;
        if (j == 9) {
            j = 0;
            i++;
        }
    }

    Solution solution;
    if (solution.isValidSudoku(board)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}