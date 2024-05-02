class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxXor = pow(2, maximumBit) - 1; // Maximum XOR value based on maximumBit

        vector<int> runXor;
        int val = 0;
        for (int num : nums) {
            val ^= num;
            runXor.push_back(val);
        }

        vector<int> ans;
        for (int i = runXor.size() - 1; i >= 0; i--) {
            // For each prefix, find the maximum XOR value
            // dry the for the test case {0, 1, 1, 3}
            int prefixXor = runXor[i];
            int xorWithMax = maxXor ^ prefixXor; // Find XOR with maximum possible XOR value
            ans.push_back(xorWithMax);
        }

        return ans;
    }
};
