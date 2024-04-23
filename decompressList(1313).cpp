class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        for(int i = 1; i < nums.size();){
            int freq = nums[i-1];
            int val = nums[i];
            while(freq--) ans.push_back(val);
            i+=2;
        }
        return ans;
    }
};