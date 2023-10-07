class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int dp[51][102][102];
        memset(dp,-1,sizeof(dp));
        int mod = 1e9+7;
        function<long long(int,int,int)> helper = [&](int i,int max_ele,int cost)->long long{
            if(i == n) {
                if(cost == k) return 1;
                else {
                    return 0;
                }
            }
            if(dp[i][max_ele+1][cost]!=-1) return dp[i][max_ele+1][cost];
            long long ans = 0;
            for(int j = 1;j<=m;j++){
                int c1 = max_ele;
                int c2 = cost;
                if(max_ele<j){
                    c1 = j;
                    c2 = cost+1;
                }
                ans = (ans+helper(i+1,c1,c2))%mod;
            }
            return dp[i][max_ele+1][cost] = (ans)%mod;
        };
        return helper(0,-1,0);
    }
};