class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        // just calculate the prefix sum k times
        vector<int>temp(n, 1);
        for(int i = 0; i < k; i++){
            for(int i = 1; i < n; i++){
                temp[i] = temp[i] + temp[i-1];
            }
        }
        return temp[k-1][n-1];
    }
};s