/*
Since we just need to find the min time to remove ballons, we can take the total sum of consecutive same character and then just remove the max cost from the total cost..
*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // where ever you find same consecutive elements, just remove the one with less time
        int ans = 0;
        int total = neededTime[0], mx = neededTime[0];
        for(int i = 1; i < colors.size(); i++){
            if(colors[i]==colors[i-1]){
                total+=neededTime[i];
                mx = max(mx, neededTime[i]);
            }
            else{
                //current char does not match the previous implies that it is a new character..
                ans += total-mx;
                total = neededTime[i];
                mx = neededTime[i];
            }
        }
        //add the last group cost as well
        ans += total-mx;
        return ans;
    }
};