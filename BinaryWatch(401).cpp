class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        // led should be less than 9 only then only you can actually build valid time
        vector<string>ans;
        //the best way to do this question is to count the no of set bits in hour and minutes that are in the range (0-11) and (0-59) respectively so that we can get all the different combinations
        // dry for 4 turned on bits
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60; m++){
                if(__builtin_popcount(h) + __builtin_popcount(m)==turnedOn){
                    string minutes = m < 10 ? "0"+to_string(m) : to_string(m);
                    string temp = to_string(h)+":"+minutes;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};