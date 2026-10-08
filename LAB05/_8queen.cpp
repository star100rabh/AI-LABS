#include <iostream>
using namespace std;

const int N = 8;
int board[N][N] = {0};

// Check whether a queen can be placed here.
bool isSafe(int row, int col) {
    // Check the column above.
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper-left diagonal.
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper-right diagonal.
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row) {
    // All 8 queens have been placed.
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            // Undo this placement and try another column.
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    if (solve(0)) {
        cout << "One solution:\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}