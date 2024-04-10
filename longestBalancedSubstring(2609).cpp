class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int len = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == '0' && s[i] == '1')
            {
                int j = i - 1, k = i;
                // traverse both simultaneously 
                int temp = 0;
                while (j >= 0 && k < s.size())
                {
                    if (s[j] == '0' && s[k] == '1')
                    {
                        temp += 2;
                        j--;
                        k++;
                    }
                    else break;
                }
                // get the len
                len = max(len, temp);
            }
        }
        return len;
    }
};