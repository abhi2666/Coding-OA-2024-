class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans = "";
        unordered_set<string>st(banned.begin(), banned.end());
        unordered_map<string, int>mp;
        unordered_set<char>symbols = {'!','?',',',';','.',' '};
        for(int i = 0; i < paragraph.size(); i++) {
            if(paragraph[i] != ' '){
                paragraph[i] = tolower(paragraph[i]);
            }
            
        }
        // now segeregate words and put them into map
        string temp;
        for(int i = 0; i < paragraph.size(); i++){
            if(symbols.find(paragraph[i])==symbols.end()){
                temp += paragraph[i];
            }
            else{
                mp[temp]++;
                temp = "";
            }
        }
        if(!temp.empty()) {
            mp[temp]++;
        }
        // for(auto it : mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int mxfreq = -1;
        for(auto it : mp){
            if(st.find(it.first)==st.end() && it.second > mxfreq) {
                ans = it.first;
                mxfreq = it.second;
            }
        }
        return ans;

    }
};