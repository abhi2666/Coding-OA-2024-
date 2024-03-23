class Solution {
public:
    // find players with zero or one losses
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        sort(matches.begin(), matches.end());
        unordered_map<int, int>mp;
        unordered_set<int>st;//store all the elements 
        for(auto match : matches){
            mp[match[1]]++;
            st.insert(match[0]);
            st.insert(match[1]);
        }

        vector<vector<int>>ans;
        vector<int>zeroLosses;
        for(auto ele : st){
            if(mp.find(ele)==mp.end()) zeroLosses.push_back(ele); //no in lostmap
        }
        vector<int>oneLosses;
        for(auto it : mp){
            if(it.second==1) oneLosses.push_back(it.first);
        }
        ans.push_back(zeroLosses);
        ans.push_back(oneLosses);
        return ans;

    }
};