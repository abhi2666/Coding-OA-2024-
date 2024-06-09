class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // use prefix sum approach to store the running sum..
        int prefixSum = 0, mxLen = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            prefixSum += A[i];
            if (prefixSum == 0)
            {
                mxLen = max(mxLen, i - 0 + 1);
            }
            if (map.find(prefixSum) != mp.end())
            {
                // you found the current prefix sum
                mxLen = max(mxLen, i - mp[prefixSum]);
            }
            else
            {
                mp[prefixSum] = i;
            }
        }
        return mxLen;
    }
};
