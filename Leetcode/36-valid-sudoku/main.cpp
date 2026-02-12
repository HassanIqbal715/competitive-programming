#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>> board) {
    int arrVert[9][9] = {0};
    int arrHorz[9][9] = {0};
    int arrSec[9][9] = {0};
    int index = 0;
    int secCol = 0;
    int secRow = 0;
    int jCol = 0;
    int jRow = 0;

    for (int i = 0; i < 9; i++) {
        secCol = (i % 3) * 3;
        secRow = (i / 3) * 3;
        for (int j = 0; j < 9; j++) {
            jCol = (j % 3) + secCol;
            jRow = (j / 3) + secRow;
            if (board[i][j] != '.') {
                index = board[i][j] - '1';
                if (arrHorz[i][index] != 1) arrHorz[i][index] = 1;
                else return false;
            }
            if (board[j][i] != '.') {
                index = board[j][i] - '1';
                if (arrVert[i][index] != 1) arrVert[i][index] = 1;
                else return false;
            }
            if (board[jRow][jCol] != '.') {
                index = board[jRow][jCol] - '1';
                if (arrSec[i][index] != 1) arrSec[i][index] = 1;
                else return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
      {'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'} 
    };
    cout << isValidSudoku(board) << endl;
}