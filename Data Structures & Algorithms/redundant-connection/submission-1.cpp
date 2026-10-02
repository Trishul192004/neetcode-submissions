class Solution {
public:

    bool dfs(int node, int target,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        // We reached the target
        if(node == target)
            return true;

        // Mark current node as visited
        visited[node] = true;

        // Explore all neighbours
        for(int neighbor : adj[node]) {

            if(!visited[neighbor]) {

                if(dfs(neighbor, target, adj, visited))
                    return true;
            }
        }

        // Target cannot be reached
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        // Adjacency list
        vector<vector<int>> adj(n + 1);

        // Process every edge
        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Fresh visited array for this DFS
            vector<bool> visited(n + 1, false);

            // Check if u and v are already connected
            if(dfs(u, v, adj, visited)) {

                // Adding this edge would create a cycle
                return edge;
            }

            // No path exists, so safely add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};