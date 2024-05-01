class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        int i;
        for(i = 0; i < word.size(); i++){
            if(word[i]==ch) break;
        }
        if(i==word.size()) return word;
        else{
            string temp = word.substr(0, i + 1);
            reverse(temp.begin(), temp.end());
            ans = temp + word.substr(i+1);
        }
        return ans;
    }
};