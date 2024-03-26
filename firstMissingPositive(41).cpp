/*
1 <= nums[i] <= nums.size()
To solve this, try to put every element in its rightful index like 1 at first index..
This can be done easily using a loop to check for positive elements only..
At last check if nums[i] != i + 1 and then return i + 1 that is the smallest element missing
*/
// try to dry run it for {3, 4, -1, 1} and you will understand the logic
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int ele = nums[i];
            // check if ele is in its right place..if not swap it in its right place
            while(ele >= 1 && ele <= n && ele!=i+1 && nums[ele-1]!=ele){
                swap(nums[i], nums[ele-1]);
                ele = nums[i];
            }
        }
        // now check 
        for(int i = 0; i < n; i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1; // becuase if all the elements is present from 1 to n then the smallest positive element that is not present is n+1
    }
};