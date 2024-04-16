class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int cnt_zeroes = nums[0]==0 ? 1 : 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1]==nums[i]){
                nums[i-1] *= 2;
                nums[i] = 0;
                cnt_zeroes++;
            }
            else if(nums[i]==0) cnt_zeroes++;
        }
        // now shift zeroes to the end
        vector<int>ans;
        for(auto ele : nums){
            if(ele!=0) ans.push_back(ele);
        }
        while(cnt_zeroes--) ans.push_back(0);
        return ans;
    }
};