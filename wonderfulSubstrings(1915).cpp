class Solution {
public:
// this technique will not work and you will have to use some bitmasking kind of technique
    long long wonderfulSubstrings(string word) {
        long long count = 0;
        unordered_map<char, int>mp; // to keep track of char and its freq   
        int oddCnt = 0;
        int i = 0, j =0 ;
        while(j < word.size()){
            mp[word[j]]++;
            if(mp[word[j]]%2) oddCnt++;
            // check for oddcnt
            while(i < j && oddCnt > 1){
                mp[word[i]]--;
                if(mp[word[i]]%2!=1) oddCnt--;
                i++;
            }
            /// store the subarrays that you can
            count += j - i + 1;
            j++;
        }
        return count;
    }
};