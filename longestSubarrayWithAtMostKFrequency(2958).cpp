/*
we can use a map to keep track of the frequencies of the elements with a map and can use two pointers to 
get the longest such subarray
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int i = 0, ans = 0;
        for(int j = 0; j < nums.size(); j++){
            mp[nums[j]]++;
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;

    }
};