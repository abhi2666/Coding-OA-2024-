//use map to store the prefix sum can be used in the future
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, preSum = 0;
        unordered_map<int, int>mp; // store prefix sum
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            if(preSum==goal) ans++;
            if(mp.find(preSum-goal)!= mp.end()) {
                ans += mp[preSum-goal];
            }
            mp[preSum]++;
        }
        return ans;
    }
};