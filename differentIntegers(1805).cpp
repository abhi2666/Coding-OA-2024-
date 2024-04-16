class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size(), count = 0;
        unordered_set<string>st; // put strings 
        for(int i = 0; i < n; i++){
            if(word[i]>='0' && word[i]<='9'){
                int j = i;
                while(j < n && word[j] >= '0' && word[j]<='9') j++;
                string temp = word.substr(i, j-i);
                // remove zeroes
                int k = 0; 
                while(k < temp.size()){
                    if(temp[k]=='0') k++;
                    else break;
                }
                temp = temp.substr(k);
                if(st.find(temp)==st.end()){
                    count++;
                    st.insert(temp);
                }
            }
            while(i < n && isdigit(word[i])) i++;
        }
        return count;
    }
};