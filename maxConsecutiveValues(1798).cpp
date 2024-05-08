/*
smart and short solution - Just sort the array and try to find the consecutive sequence
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int sum = 0;
        for(auto coin : coins){
            if(sum + 1 < coin){
                // implies that sum is missing from the array (dry run to confirm)
                return sum + 1;
            }
            sum += coin;
        }

        return sum + 1;
    }
};