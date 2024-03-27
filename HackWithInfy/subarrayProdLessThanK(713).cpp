class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //Sliding window can be used to solve this problem
        if(k<=1) return 0;
        int prod = 1;
        int i = 0, j, ans = 0;
        for(j = 0; j < nums.size(); j++){
            prod *= nums[j];
            while(i <= j && prod >= k){
                prod /= nums[i];
                i++;
            }
            ans += (j-i+1);
        }
        return ans;
    }
};