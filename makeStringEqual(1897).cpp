class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // to check if you can make all the strings equal you have to check the freq of each 
        // character in total and they should all be equal
        unordered_map<char, int>mp;
        for(auto word : words){
            for(auto ch : word) mp[ch]++;
        }
        // now check for each character if it can be used in n words in vector
        int n = words.size();
        for(auto it : mp){
            if(it.second%n) return false;
        }
        return true;
    }
};