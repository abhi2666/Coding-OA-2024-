class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // create running xor array of the nums
        vector<int>runXor;
        int val = 0;
        for(auto ele : nums) {
            val ^= ele;
            runXor.push_back(val);
        }

        vector<int>ans;
        // k < 2^maximumbit 
        // for every iteration discard the last element
        for(int i = runXor.size()-1; i >= 0; i--){
            int temp = runXor[i];
            // find a value of k that will give the max XOR result with this 
            int t = pow(2, maximumBit) - 1, currMax = temp, mx = temp;
            while(t--){
                currMax ^= t;
                if(currMax > mx){
                    mx = currMax;
                }
                currMax = temp; // try k, k - 1, k - 2 ... for same value of temp
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

