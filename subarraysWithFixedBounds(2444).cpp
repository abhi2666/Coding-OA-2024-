/*
count subarrays where the min ele = minK and max ele  = maxK..
Approach -> look for l (min) and r(max) indexes and also bad index which represents an element that is out of the range which implies that you will have to find the new l and r that comes after this bad index..
formula ans += max(0, min(l, r) - badIndex) // to effectively calculate the subarray
*/
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int left = -1, right = -1, bad = -1;
        for(int i = 0; i < nums.size(); i++){
            //check for bad element that does not comes into the range
            if(!(nums[i] >= maxK && nums[i] <= minK)){
                bad = i;
            }

            if(nums[i]==minK) left = i;
            if(nums[i]==maxK) right = i;

            ans += max(0, min(left, right) - bad);
        }
        return ans;

    }
};