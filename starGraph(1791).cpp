class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //no graph algo is necessary 
        unordered_map<int, int>mp; //node and freq
        for(auto it : edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        int n = mp.size();
        for(auto it : mp){
            if(it.second==n-1) return it.first;
        }
        return -1;
    }
};