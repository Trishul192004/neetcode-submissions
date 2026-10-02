class Solution {
public:
    bool dfs(int node,int target,vector<vector<int>>&adj,vector<bool>&visited){

        if(node == target) return true;
        
        visited[node] = true;

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,target,adj,visited)) return true;
            }
        }
        //target cant reach
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();

            vector<vector<int>> adj(n+1);

            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];

                vector<bool>visited(n+1,false);

                if(dfs(u,v,adj,visited)){
                    return edge; //if u and v already connected coz cycle happen by edge 
                }

                adj[u].push_back(v);    //no path exists safely add edge
                adj[v].push_back(u);
            }

            return {};
    }
};
