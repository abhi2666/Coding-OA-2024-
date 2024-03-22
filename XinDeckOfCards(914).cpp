class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        /// only way to do the question is to take gcd of all the frequencies of all numbers beucase it will provide with the greatest common divisor that will act as a X to partition the array in size X. X > 1 is a must condition
        unordered_map<int, int>mp;
        for(auto ele : deck) mp[ele]++;
        int gcd = 0;
        for(auto it : mp){
            if(gcd==0) gcd = it.second;
            else {
                gcd = __gcd(gcd, it.second); //to get gcd of two numbers
            }
        }
        if(gcd > 1) return true;
        else return false;
    }
};