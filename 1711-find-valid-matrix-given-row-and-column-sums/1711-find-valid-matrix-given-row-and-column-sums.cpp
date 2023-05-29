class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int a,b;
        vector<vector<int>> ans(rowSum.size(),vector<int>(colSum.size()));
        for(int i = 0;i<rowSum.size();i++){
            for(int j = 0;j<colSum.size();j++){
                a = rowSum[i];
                b = colSum[j];
                ans[i][j]+=min(a,b);
                rowSum[i]-=min(a,b);
                colSum[j]-=min(a,b);
            }
        }
        return ans;
    }
};