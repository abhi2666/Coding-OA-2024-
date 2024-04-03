class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // use an actual stack to simulate 
        stack<int>st;
        int i = 0;
        for(int j = 0; j < pushed.size(); j++){
            //push element 
            st.push(pushed[j]);
            //check if the current st.top is the one that we have to pop
            while(!st.empty() && st.top()==popped[i]){
                st.pop();
                i++;
            }
            
        }
        if(i!=popped.size()) return false;
        else return true;
    }
};