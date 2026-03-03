#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    
    st.push(node);
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V+1);

    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(V+1, false);
    stack<int> st;

    
    for (int i = 0; i < V+1; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " -> ";
    }

    return 0;
}