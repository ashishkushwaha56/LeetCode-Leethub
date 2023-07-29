class Solution {
public:
    double soupServings(int n) {
        if(n>4451) return 1.0;
        vector<double> dp(1000000,-1);
        n = (n+24)/25;
        function <double(int,int)> helper = [&](int a,int b)->double{
            if(a<=0 and b<=0) return 0.5;
            if(a<=0) return 1.0;
            if(b<=0) return 0.0;
            int cc = a*5000+b;
            if(dp[cc]!=-1) return dp[cc];
            double ans = 0.25 *(helper(a-4,b)+helper(a-3,b-1)+helper(a-2,b-2)+helper(a-1,b-3));
            return dp[cc] = ans;
        };
        return helper(n,n);
    }   
};