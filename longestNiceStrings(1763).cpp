class Solution
{
private:
    bool isValid(string temp)
    {
        set<char> st(temp.begin(), temp.end());
        for (auto ele : st)
        {
            if (ele >= 'A' && ele <= 'Z')
            {
                // Check if both lowercase and uppercase versions exist
                if (st.find(tolower(ele)) == st.end() || st.find(toupper(ele)) == st.end())
                    return false; // Couldn't find either version
            }
            else if (ele >= 'a' && ele <= 'z')
            {
                // Check if both lowercase and uppercase versions exist
                if (st.find(toupper(ele)) == st.end() || st.find(tolower(ele)) == st.end())
                    return false; // Couldn't find either version
            }
        }
        return true;
    }

public:
    string longestNiceSubstring(string s)
    {
        if (s.size() == 1)
            return "";
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                string temp = s.substr(i, j - i + 1);
                // now check
                if (isValid(temp))
                {
                    if (temp.size() > ans.size())
                    {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};