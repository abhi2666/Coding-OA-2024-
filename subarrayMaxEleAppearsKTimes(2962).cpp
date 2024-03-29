/*
count subarrays where the max element comes at least k times
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        int count = 0, n = nums.size();
        int i = 0;
        for(int j = 0; j < n; i++){
            if(nums[j]==mx) count++;
            while(count >= k){
                if(nums[i]==mx) count--;
                ans += n-right; // main logic- dry run with some examples
            }
        }
        return ans;

    }
};