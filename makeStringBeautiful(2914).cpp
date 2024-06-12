/*
Approach - since we have to diving the strings into even partition only, we can check for change in 2 chars at a time and keeping track of the changes required
*/
class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i+=2){
            if(s[i]!=s[i+1]) cnt++;
        }
        return cnt;
    }
};