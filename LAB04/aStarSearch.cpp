#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;

struct Node {
    int r, c, g, f;
    bool operator<(const Node& other) const {
        return f > other.f; // Smallest f first
    }
};

int main() {
    int grid[3][3] = {{0, 0, 0},
                      {1, 1, 0},
                      {0, 0, 0}};
    vector<vector<int>> dist(3, vector<int>(3, INT_MAX));
    priority_queue<Node> pq;

    auto h = [](int r, int c) {
        return abs(2 - r) + abs(2 - c);
    };

    dist[0][0] = 0;
    pq.push({0, 0, 0, h(0, 0)});
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();

        if (u.g != dist[u.r][u.c]) continue;
        if (u.r == 2 && u.c == 2) {
            cout << "Shortest distance: " << u.g << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i], c = u.c + dc[i];
            if (r < 0 || r >= 3 || c < 0 || c >= 3) continue;

            if (grid[r][c] == 0 && u.g + 1 < dist[r][c]) {
                dist[r][c] = u.g + 1;
                pq.push({r, c, u.g + 1, u.g + 1 + h(r, c)});
            }
        }
    }
    cout << "No path\n";
}