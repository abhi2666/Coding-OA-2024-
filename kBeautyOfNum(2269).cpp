class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        // 1 2 3
        // 0 1 2 
        int ans = 0;
        for(int i = 0; i <= s.size()-k; i++){
            string temp = s.substr(i, k);
            int n = stoi(temp);
            if(n==0) continue;
            if(num%n==0) ans++;
        }
        return ans;
    }
};