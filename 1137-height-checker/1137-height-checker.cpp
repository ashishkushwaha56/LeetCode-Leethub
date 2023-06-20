class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v = heights;
        sort(v.begin(),v.end());
        int cnt = 0;
        for(int i = 0;i<heights.size();i++){
            cnt+=(v[i]!=heights[i]);
        }
        return cnt;
    }
};