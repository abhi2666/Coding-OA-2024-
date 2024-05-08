/*
Percieve the question as an undirected graph and then apply traversal to figure out the order in which they will be placed..
*/
class Solution {
private:
    void dfs(int ele, vector<int>&ans, unordered_set<int>&vis, unordered_map<int, vector<int>>adj){
        vis.insert(ele);
        ans.puhs_back(ele);
        for(auto neigh : adj[ele]){
            if(vis.find(neigh)==vis.end()) dfs(neigh, ans, vis, adj);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        vector<int>ans;
        int n = INT_MIN;
        unordered_map<int, int>mp;
        for(auto p : pairs){
            mp[p[0]]++;
            mp[p[1]]++;
            n = max({n, p[0], p[1]});
        }
        int ele = -1;
        for(auto it : mp){
            if(it.second==1) {
                ele = it.first;
                break;
            }
        }
        // create a graph also - becuase of negative elements present also we cannot use array to create the graph that is why we will use a map<int, vector<int>>mp to craete undirected graph..
        // To Be done
        unordered_map<int, vector<int>>adj;
        for(auto p : pairs){
            mp[p[0]].push_back(p[1]);
            mp[p[1]].push_back(p[0]);
        }
        unordered_set<int>vis;
        dfs(ele, ans, vis, adj);
        return ans;
    }
};