class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(),points.end());
        int right = points[0][1];
        for(int  i =0;i<points.size();i++){
            if(right<points[i][0]){
                ans++;
                right = points[i][1];
            }
            else {
                right = min(right,points[i][1]);
            }
        }
        return ans;
    }
};