class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0, cnt = 0;
        for(auto ch : s){
            if(ch=='E') cnt++;
            else if(ch=='L') cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};