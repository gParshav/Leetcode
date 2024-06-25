#include <vector>

class Solution {
public:
    bool isValid(char k, int row, int col, std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == k) {
                return false;
            }

            if (board[i][col] == k) {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k) {
                return false;
            }
        } 

        return true;    
    }

    bool f(int i, int j, std::vector<std::vector<char>>& board) {
        if (i == 9) {
            return true; // Solved successfully
        }

        if (j == 9) {
            return f(i + 1, 0, board); // Move to the next row
        }

        if (board[i][j] != '.') {
            return f(i, j + 1, board); // Skip filled cells
        }

        for (char k = '1'; k <= '9'; k++) {
            if (isValid(k, i, j, board)) {
                board[i][j] = k;
                if (f(i, j + 1, board)) {
                    return true;
                }
                board[i][j] = '.'; // Undo move (backtrack)
            }
        }

        return false; // Trigger backtracking
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        f(0, 0, board);
    }
};
