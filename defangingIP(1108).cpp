class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(auto ele : address){
            if(ele!='.') ans+=ele;
            else {
                ans += "[.]";
            }
        }
        return ans;
    }
};