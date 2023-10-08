class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<long long>> dp(nums1.size(),vector<long long>(nums2.size(),INT_MIN));
        function<long long(int,int)> helper = [&](int i,int j)->long long{
            if(i == nums1.size() or j == nums2.size()) return INT_MIN;
            if(dp[i][j]!=INT_MIN) return dp[i][j];
            
            long long a = nums1[i]*nums2[j]+max(helper(i+1,j+1),0ll);
            long long b = helper(i+1,j);
            long long c = helper(i,j+1);
            return dp[i][j] = max({a,b,c});
        };
        return helper(0,0);
    }
};