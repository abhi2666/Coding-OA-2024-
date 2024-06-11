class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        unordered_map<int, int>mp; // to keep track of unqiue elements count
        for(auto ele : arr1) mp[ele]++;
        sort(arr1.begin(), arr1.end());
        for(auto ele : arr2){
            if(mp.find(ele)!=mp.end()){
                // element exists
                int cnt = mp[ele];
                while(cnt--) ans.push_back(ele);
            }
        }
        // now put those elements in the ans that are not present in the arr2
        unordered_set<int>st (arr2.begin(), arr2.end());
        for(auto ele : arr1){
            if(st.find(ele)==st.end()) ans.push_back(ele);
        }
        return ans;
    }
};