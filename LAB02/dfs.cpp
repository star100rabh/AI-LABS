#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (visited[node])
            continue;

        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5;

    vector<vector<int>> adj(n);

    // Graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    cout << "DFS Traversal: ";

    DFS(0, adj, n);

    return 0;
}