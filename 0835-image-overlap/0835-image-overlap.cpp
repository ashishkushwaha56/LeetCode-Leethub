class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> a1,a2;
        for(int i = 0;i<img1.size();i++){
            for(int j = 0;j<img1[i].size();j++){
                if(img1[i][j] == 1) a1.push_back({i,j});
                if(img2[i][j] == 1) a2.push_back({i,j});
            }
        }
        int ans = 0;
        map<pair<int,int>,int> mb;
        for(auto &it:a1){
            for(auto &it1:a2){
                int x = (it.first-it1.first);
                int y = (it.second-it1.second);
                mb[{x,y}]++;
                ans = max(ans,mb[{x,y}]);
            }
        }
        return ans;
    }
};