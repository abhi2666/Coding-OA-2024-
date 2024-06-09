class Solution
{
public:
    // same as book allocation problem

    // If we can allocate, such that max sum is mid
    bool isPossible(vector<int> &arr, int n, int days, int mid)
    {
        int cnt = 1;        // current day
        int currWeight = 0; // weight on current day

        for (int i = 0; i < n; i++)
        {

            // IMP condition otherwise test cases like arr =  [1,2,3,1,1] ; days = 4 will return ans = 2, but it's correct ans is 3 . DRY RUN :-)
            if (arr[i] > mid) /// for ex for day = 3 and mid = 2 // you cannot pick that shipment
            {
                return false;
            }

            if (currWeight + arr[i] <= mid)
            {
                currWeight += arr[i];
            }
            else
            {
                // move to next day
                cnt++;
                currWeight = arr[i];

                if (cnt > days)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int> &a, int days)
    {
        
        int ans = 0;
        int low = *min_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(canComplete(mid, a, days)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }   

        return ans;
    }
};