class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // there are some cases that we can follow that are very starightforward
        int n = nums.size();
        if (n <= 4)
            return 0; // because we can make the 3 elements equal to fourth element
        //these are the cases that you have to consider only
        // convert all start 3 to max ele, convert start 2 ele to max ele
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};

//recursive approach which moves two pointers till 3 moves and then check their diff
class Solution {
public:
    int solve(vector<int> arr,int i,int j,int k)
    {
      if(k==3) return arr[j]-arr[i];
      return min(solve(arr,i+1,j,k+1),solve(arr,i,j-1,k+1));
    }
    int minDifference(vector<int>& arr) {
        if(arr.size()<=4) return 0;
        sort(arr.begin(),arr.end());
        return solve(arr,0,arr.size()-1,0);
    }
};