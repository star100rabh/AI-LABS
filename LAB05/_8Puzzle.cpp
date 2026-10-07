#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void display(string state) {
    for (int i = 0; i < 9; i++) {
        cout << state[i] << " ";
        if ((i + 1) % 3 == 0)
            cout << "\n";
    }
    cout << "\n";
}

void bfs(string start, string goal) {
    queue<string> q;
    map<string, string> parent;

    q.push(start);
    parent[start] = "";
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == goal) {
            vector<string> path;
            for (string state = current; state != ""; state = parent[state]) {
                path.push_back(state);
            }

            reverse(path.begin(), path.end());

            cout << "Minimum moves: " << path.size() - 1 << "\n\n";

            for (int i = 0; i < (int)path.size(); i++) {
                cout << "Step " << i << ":\n";
                display(path[i]);
            }
            return;
        }

        int blank = current.find('0');
        int row = blank / 3;
        int col = blank % 3;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (newRow >= 0 && newRow < 3 &&
                newCol >= 0 && newCol < 3) {

                int newPosition = newRow * 3 + newCol;

                string next = current;
                swap(next[blank], next[newPosition]);
                if (parent.find(next) == parent.end()) {
                    parent[next] = current;
                    q.push(next);
                }
            }
        }
    }

    cout << "No solution exists.\n";
}

int main() {
    string start = "123406758";
    string goal  = "123456780";

    bfs(start, goal);

    return 0;
}