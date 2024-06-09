/*
since the string is only rotated, we can create a new string goal+goal and it will cover the string s if it is a valid rotation of the string goal.

Note :- strings lengths must be same then only checking is possible.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false; // not possible 
        // just concatenate the goal with itself then inside of it look for s
        string nw = goal+goal;
        int i = 0;
        for(int i = 0; i < nw.size(); i++){
            if(s[0]==nw[i]){
                int j = 0, k = i;
                while(j < s.size()){
                    if(s[j]!=nw[k]){
                        break;
                    }
                    else{
                        j++;
                        k++;
                    }
                }
                if(j==s.size()) return true;
            }
        }
        return false;
    }
};