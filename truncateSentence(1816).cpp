// class Solution {
// public:
//     string truncateSentence(string s, int k) {
//         int j = 0, n = s.size();
//         while(j < n){
//             while(j < n && s[j]==' ') j++;
//             // now look for a space, that will means you got a word
//             while(j < n && s[j]!=' ') j++;
//             k--;
//             if(k==0) break;
//         }
//         string ans = s.substr(0, j-0);
//         return ans;
//     }
// };

// optimised code
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i]==' '){
                k--;
                if(k==0) break; 
            }
            ans[i]+=s[i];
        }
        return ans;
    }
};