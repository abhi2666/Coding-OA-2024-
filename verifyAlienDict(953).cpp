class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>mp;
        for(int i = 0; i < order.size(); i++) mp[order[i]] = i;
        // now pick words and check 
        for(int k = 0; k < words.size()-1; k++){
            string w1 = words[k];
            string w2 = words[k+1];
            int i = 0, j = 0;
            while(i < w1.size() && j < w2.size()){
                if(mp[w1[i]] > mp[w2[j]]) {
                    //sequence is fucked 
                    return false;
                }
                else if(mp[w1[i]] < mp[w2[j]]){
                    // no need to check furthur 
                    break;
                }
                i++;
                j++;
            }
            if(i==w1.size() || j==w2.size() && w2.size() < w1.size()) return false;
        }
        return true;
    }
};