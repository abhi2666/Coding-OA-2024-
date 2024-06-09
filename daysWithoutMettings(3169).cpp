/*
Approach - just sort and merge the intervals, then subtract the working days from the total 
days
*/
class Solution {
private:
// remember the logic to implement merge intervals
    vector<vector<int>> mergeIntervals(vector<vector<int>>& meetings){
        vector<vector<int>>ans;
        vector<int> temp = meetings[0];
        for(int i = 1; i < meetings.size(); i++){
            // intervals will either merge or then will not
            if(temp[1] >= meetings[i][0]){
                //means we can merge them
                temp[0] = min(temp[0], meetings[i][0]);
                temp[1] = max(temp[1], meetings[i][1]);
            }
            else{
                ans.push_back(temp);
                temp = meetings[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>>merged = mergeIntervals(meetings);    
        for(auto it : merged){
            days -= (it[1]-it[0]+1); /// getting the days where the employee was free..
        }
        return days;
    }
};