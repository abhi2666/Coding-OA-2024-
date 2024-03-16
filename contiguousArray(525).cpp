class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        // using a map to keep track of prefix sum
        //  if for len l the sum  = l/2 that means that a valid subarray
        unordered_map<int, int> mp;
        mp[0] = -1;
        int zeroes = 0, ones = 0, mxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i]==0 ? ++zeroes : ++ones;
            // check their diff 
            int diff = zeroes - ones;
            if(mp.find(diff) != mp.end()){
                mxLen = max(mxLen, i - mp[diff]);
            }
            else{
                mp[diff] = i;
            }
        }
        return mxLen;
    }
};