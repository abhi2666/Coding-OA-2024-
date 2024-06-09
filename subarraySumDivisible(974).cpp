class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // store and the index
        unordered_map<int, int>mp; // sum, idx
        int prefixSum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            if(prefixSum%k==0) ans++;
            int rem = (prefixSum%k + k)%k; // to handle the negative values
            if(mp.find(rem)!=mp.end()){
                // means you got the sum
                ans += mp[rem];
            }
            mp[prefixSum]++;
        }
        return ans;
    }
};