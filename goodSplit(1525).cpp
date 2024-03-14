class Solution {
public:
    int numSplits(string s) {
        // pre compute the distinct chars from left and right using a set for 
        //every index
        int n = s.size();
        unordered_set<char>st;
        vector<int>left(n), right(n);
        for(int i = 0; i < n; i++){
            st.insert(s[i]);
            left[i] = st.size();
        }
        st.clear();
        for(int i = n-1; i >= 0; i--){
            st.insert(s[i]);
            right[i] = st.size();
        }
        // now check for every index its left and right
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            if(left[i]==right[i+1]) ++cnt;
        }
        return cnt;
    }
};