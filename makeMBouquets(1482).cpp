/*
Question - make m bouquets from n flowers that will bloom on different days and for each bouquet pick k adjacent flowers only that are already bloomed..

Approach - Binary search to look min value of day in which we can form m bouquets
*/
class Solution
{
private:
    bool isPossible(int day, vector<int>&bd, int m, int k){
        // find total bouquets formed and check its enough
        // note : - only adjacent flowers are required to form the bouquets
        int cnt = 0, totalBouquets = 0;
        for(auto ele : bd){
            if(ele <= day){
                //will bloom
                cnt++;
            }
            else{
                // check how many bouquets formed
                totalBouquets += (cnt/k);
                cnt = 0;
            }
        }
        // add remaining bouquets 
        totalBouquets += (cnt/k);
        if(totalBouquets >= m) return true;
        else return false;
    }
public:
    int minDays(vector<int> &bd, int m, int k)
    {
        int totalFlowers = m*1ll*k*1ll;
        if( > bd.size()) return -1; //does not enough flowers to form m bouquets
        int low = INT_MAX, high = INT_MIN;
        for(auto ele : bd){
            low = min(low, ele);
            high = max(high, ele);
        }
        //range 
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(mid, bd, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};