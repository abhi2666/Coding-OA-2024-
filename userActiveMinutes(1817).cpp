class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>ans(k, 0);
        unordered_map<int, int>mp; // time and freq
        //store every elements in set to remove duplicate elements
        set<vector<int>>st(logs.begin(), logs.end()); 
        for(auto it : st){
            mp[it[0]]++; // based on it we are storing
        }

        for(auto it : mp){
            if(it.second > 0){
                ans[it.second-1] += 1;
            }
        }
        return ans;
    }
};