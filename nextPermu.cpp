// can be applied with a string
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // we have to find the lexographical next element
        int i;
        for(i = nums.size()-2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                break;
            }
        }
        if(i == -1) {
            // means string is in descending order
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // now find the just greater element from the right
        for(int j = nums.size()-1; j > i; j--){
            if(nums[j] > nums[i]){
                swap(nums[i], nums[j]);
                break;
            }
        }
        // now reverse from i + 1 to n
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
};