/* IMPORTANT
find majority element that has freq more than n/3.

Approach -> Boyer's Moore Voting Algorithm
There can only be at max 2 elements with more than n/3 freq.
So keep a find those two elements using count vars and then 
at last check if they actually are more than n/3 times.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int ele1 = 0, ele2 = 0, c1 = 0, c2 = 0;
        for(auto ele : nums){
            if(ele==ele1) c1++;
            else if(ele==ele2) c2++;
            else if(c1==0){
                ele1 = ele;
                c1++;
            }
            else if(c2==0){
                ele2 = ele;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }

        // now check their validity
        int c1 = 0, c2 = 0, n = nums.size()/3;
        for(auto ele : nums){
            if(ele==ele1) c1++;
            else if(ele==ele2) c2++;
        }
        if(c1 > n) ans.push_back(ele1);
        if(c2 > n) ans.push_back(ele2);
        return ans;
    }
};