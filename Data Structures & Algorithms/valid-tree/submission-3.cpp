class Solution {
public:

    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        visited[node] = true;

        for(int neighbour : adj[node]) {

            // Don't go back to the node we came from
            if(neighbour == parent) {
                continue;
            }

            // Already visited = cycle
            if(visited[neighbour]) {
                return false;
            }

            // Move to neighbour
            if(!dfs(neighbour, node, adj, visited)) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // Tree with n nodes has n-1 edges
        if(edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        // Build adjacency list
        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // Start DFS from node 0
        if(!dfs(0, -1, adj, visited)) {
            return false;
        }

        // Check all nodes are visited
        for(int i = 0; i < n; i++) {

            if(!visited[i]) {
                return false;
            }
        }

        return true;
    }
};