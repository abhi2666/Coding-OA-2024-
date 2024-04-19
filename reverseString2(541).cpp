class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i+=2*k){
            // reverse the string in the range only if range is available
            if(i+k <= n){
                reverse(s.begin()+i, s.begin()+i+k);
            }
            else{
                // reverse whatever is left
                // If there are fewer than k characters left, reverse all of them
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }
};