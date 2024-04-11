// to be done...
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // just create a map that holds the char and and its mapped char in it
        string ans = "";
        map<char, vector<char>>mp;
        for(int i = 0; i < s1.size(); i++){
            if(mp.find(s2[i])!=mp.end()){
                mp[s2[i]].push_back(s1[i]);
            }
            else{
                mp[s1[i]].push_back(s2[i]);
            }
        }
        // now sort each vectors so as to create lexo smallest string
        for(auto ele : baseStr){
            vector<char>temp = mp[ele];
            sort(temp.begin(), temp.end());
            if(ele < temp[0]){
                ans+=ele;
            }
            else{
                ans+=temp[0];
            }
        }
        return ans;
    }
};