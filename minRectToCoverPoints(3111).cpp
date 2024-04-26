class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        // for(auto it: points) cout<<it[0]<<" "<<it[1]<<endl;
        /// no need to care for how high they are in y axis
        int minRect = 0, curSide = -1;
        for(int i = 0; i < points.size(); i++){
            if(curSide==-1){
                minRect++;
                curSide = points[i][0];
            }
            else if(points[i][0]-curSide > w){ ///// silly mistake here
                minRect++;
                curSide = points[i][0];
            }
        }
        return minRect;
    }
};