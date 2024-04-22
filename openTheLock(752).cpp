class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // get min no of operations to reach the required target
        unordered_set<string>st(deadends.begin(), deadends.end());
        if(st.find("0000")!=st.end()) return -1;
        if(target=="0000") return 0; // already in the target
        /// using BFS approach to solve this question
        queue<string>q; // stores intermediate strings
        int ans = 0;
        q.push({"0000"});
        while(!q.empty()){
            ++ans; // represent the number of turns
            for(int i = q.size(); i > 0; i--){
                // get each word from queue and try to change char by char in them using a loop
                string word = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    char currentChar = word[j];
                    // change this character in + and - directions
                    word[j] = word[j]=='9' ? '0' : word[j] + 1;
                    if(word==target) return ans;
                    // check if its a deadend
                    if(st.find(word)==st.end()){
                        //means this is a valid config
                        q.push(word);
                        // also push it into stack to avoid any looping and repitions
                        st.insert(word);
                    }
                    word[j] = currentChar;
                    // now go in negative direction by decreasing a char
                    word[j] = word[j]=='0' ? '9' : word[j] - 1;
                    if(word==target) return ans;
                    if(st.find(word)==st.end()){
                        q.push(word);
                        st.insert(word);
                    }
                    word[j] = currentChar;
                }
            }
        }
        return -1; // 
    }
};