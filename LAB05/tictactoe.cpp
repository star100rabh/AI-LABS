#include <iostream>
#include <vector>
using namespace std;

char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
vector<int> path;

// Check whether the given player has won.
bool hasWon(char player) {
    int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[lines[i][0]] == player &&
            board[lines[i][1]] == player &&
            board[lines[i][2]] == player) {
            return true;
        }
    }

    return false;
}

void display() {
    for (int i = 0; i < 9; i++) {
        cout << board[i] << " ";

        if ((i + 1) % 3 == 0)
            cout << "\n";
    }
}

// Search for one sequence ending in a win for X.
bool dfs(char player) {
    if (hasWon('X'))
        return true;

    if (hasWon('O'))
        return false;

    for (int i = 0; i < 9; i++) {
        if (board[i] == '-') {
            board[i] = player;
            path.push_back(i);

            char nextPlayer = (player == 'X') ? 'O' : 'X';

            if (dfs(nextPlayer))
                return true;

            // Undo the move and explore another possibility.
            board[i] = '-';
            path.pop_back();
        }
    }

    // No winning sequence found, including a full-board draw.
    return false;
}

int main() {
    cout << "Positions:\n";
    cout << "1 2 3\n4 5 6\n7 8 9\n\n";

    if (dfs('X')) {
        cout << "One possible winning sequence:\n";

        char player = 'X';

        for (int position : path) {
            cout << player << " plays at position "
                 << position + 1 << "\n";

            player = (player == 'X') ? 'O' : 'X';
        }

        cout << "\nFinal board:\n";
        display();

        cout << "\nX wins!\n";
    } else {
        cout << "No winning sequence found.\n";
    }

    return 0;
}