// not working
// class Solution
// {
// public:
//     vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
//     {
//         int n = freq.size();
//         vector<long long> ans(n);
//         priority_queue<long long, vector<long long>> pq; // holds the max frequency at the top
//         unordered_map<int, long long>mp; // ele freq
//         for(int i = 0; i < n; i++){
//             mp[nums[i]] += freq[i];
//             pq.push(mp[nums[i]]);
//             ans[i] = pq.top();
//         }

//         return ans;
//     }
// };

// working
class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        // Please Upvote :)
        unordered_map<long long, long long> mp;
        int i, j;
        vector<long long> v(nums.size());
        priority_queue<pair<long long, long long>> pq;
        for (i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]], nums[i]});
            while (pq.size() > 0 && mp[pq.top().second] != pq.top().first) // dry run the code to better understand this condition
            {
                //this condition check for if the value(freq) for some num is same as that of its freq in the map because map holds the latest freq for a num and if the pq.top().first doesn't matches with the map[nums[i]] means that the value at top of pq.top() is not the latest value and has been changed to something else so remove it..(will only happen if some negative freq[i] appears)
                pq.pop();
            }
            v[i] = (pq.top().first);
        }
        return v;
    }
};