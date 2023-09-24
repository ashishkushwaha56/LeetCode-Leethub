class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100,vector<double>(100,-1));
        function<double(int,int)> helper = [&](int row,int glass)->double{
            if(row <0 or glass<0 or glass>row) return 0.0;
            if(row == 0 and glass == 0) return (double)poured;
            if(dp[row][glass]>-1) return dp[row][glass];
            double left = (helper(row-1,glass-1)-1)/2.0;
            if(left<0) left = 0;
            double right = (helper(row-1,glass)-1)/2.0;
            if(right<0) right=0;
            return dp[row][glass]= left+right;
        };
        return min(1.00,helper(query_row,query_glass));
    }
};