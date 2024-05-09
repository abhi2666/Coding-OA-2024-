class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        sort(hap.begin(), hap.end(), greater<int>());
        // pick the max k elements and sub -1 for them
        long long ans = 0;
        int sub = 0;
        for(auto ele : hap){
            if(k > 0){
                // value will drop up to 0 only
                int temp = ele - sub >= 0 ? ele-sub : 0;
                ans += temp;
                sub++;
                k--;
            }
        }
        return ans;
    }
};