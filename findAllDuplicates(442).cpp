/*
Approach -> you can tranform element to index and mark that particular element negative and if that same elements comes again then we can figure it out by checking the element it is pointing..
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]) -1; //0 based indexing
            if(nums[index] < 0){
                // already marked means that the current index has come before
                ans.push_back(index+1);
            }
            else{
                //convert element to negative (can be convert to something else like INT_MAX)
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};