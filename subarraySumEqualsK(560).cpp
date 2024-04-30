class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // use prefix sum to store the sum and keep track of a sum that you found at any given time in a map
        unordered_map<int, int>mp;
        int prefixSum = 0, count = 0;
        for(auto ele : nums){
            prefixSum += ele;
            if(prefixSum==k) count++;
            // check for preSum - k in map..if present that means there is also a subarray with sum k in there because x - k + k = x, basic maths
            if(mp.find(prefixSum-k)!=mp.end()){
                // found it on the map
                count += mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};