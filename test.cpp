class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 0; i < s.size()-1; i++){
            int a = (int)s[i];
            int b = (int)s[i+1];
            score+=abs(a-b);
        }   
        return score;
    }
};