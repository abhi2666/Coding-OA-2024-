class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        unordered_map<char, int> freq;
        int i = 0, j = 0, ans = 0;
        while (j < s.size())
        {
            freq[s[j++]]++;
            while(i < j && freq[s[j]] > 2){
                freq[[s[i]]]--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
