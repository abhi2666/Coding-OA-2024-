class Solution {
public:
// Approach is to check for intervals that are merging and if not merging then..you need extra 
// arrows
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrows = 0;
        int val = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(val >= points[i][0]){
                // there is merging
                val = min(val, points[i][1]);
            }
            else{
                //no merging..arrow needed 
                arrows++;
                val = points[i][1];
            }
        }
        return arrows;
    }
};