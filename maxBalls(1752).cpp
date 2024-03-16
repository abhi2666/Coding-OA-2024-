class Solution {
private:
    int sumDigits(int n){
        int sum = 0;
        while(n > 0){
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        // just sum for that sum increase the count
        unordered_map<int, int>mp;
        for(int i = lowLimit; i <= highLimit; i++){
            int sum = sumDigits(i);
            mp[sum]++;
        }
        int mx = INT_MIN;
        for(auto it : mp){
            mx = max(mx, it.second);
        }
        return mx;
    }
};