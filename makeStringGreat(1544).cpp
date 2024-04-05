class Solution
{
private:
    bool isAlternate(char a, char b)
    {
        if ((a - 'A' >= 0 && a - 'A' < 26 && b - 'a' >= 0 && b - 'a' < 26) || (a - 'a' >= 0 && a - 'a' < 26 && b - 'A' >= 0 && b - 'A' < 26))
        {
            if (tolower(a) == tolower(b))
                return true;
            else
                return false;
        }
        else
            return false;
    }

public:
    string makeGood(string s)
    {
        string ans = "";
        stack<char> st;
        for (auto ch : s)
        {
            st.push(ch);
            if (st.size() >= 2)
            {
                char a = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                if (!isAlternate(a, b))
                {
                    // means we have to include them in the new string
                    st.push(b);
                    st.push(a);
                }
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* more shorter way of doing the same as above
for (char c : s) {
    if (!stack.empty() && std::abs(c - stack.top()) == 32) {
        stack.pop();
    } else {
        stack.push(c);
    }
}

*/
