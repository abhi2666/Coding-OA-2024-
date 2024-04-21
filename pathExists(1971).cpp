class Solution {
private:
    void dfs(int src, vector<int>&vis, vector<int> *adj){
        vis[src] = 1;
        for(auto ele : adj[src]){
            if(vis[ele]==0){
                dfs(ele, vis, adj);
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // creating a adjacency list
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // now apply DFS
        vector<int>visited(n, 0);
        dfs(source, vis, adj);
        if(visited[destination]==1) return true;
        else return false;
    }
};