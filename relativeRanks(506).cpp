class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>temp = score;
        sort(temp.begin(), temp.end(), greater<int>());
        unordered_map<int, string>mp; // ele, ranking
        for(int i = 0; i < temp.size(); i++){
            if(i==0) mp[temp[i]] = "Gold Medal";
            else if(i==1) mp[temp[i]] = "Silver Medal";
            else if(i==2) mp[temp[i]] = "Bronze Medal";
            else mp[temp[i]] = to_string(i+1);
        }
        vector<string>ans;
        for(auto ele : score){
            ans.push_back(mp[ele]);
        }
        return ans;
    }
};