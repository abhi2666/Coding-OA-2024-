class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++)
        {
            // will have to create new interval if ans is empty or if there is no overlapping
            if(ans.size() == 0 || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else{
                // there is overlapping intervals....merge them
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};