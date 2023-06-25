class Solution {
public:
    int mod = 1e9+7;
    int check(vector<vector<int>>&dp,vector<int>&locations,int curr,int &finish,int fuel,int n){
        if(fuel<0) return 0;
        if(dp[curr][fuel]!=-1) return dp[curr][fuel];
        int ans = 0;
        if(curr == finish) ans++;
        for(int i = 0;i<n;i++){
            if(i!=curr){
                ans = (ans%mod+check(dp,locations,i,finish,fuel-abs(locations[curr]-locations[i]),n)%mod)%mod;
            }
        }
        return dp[curr][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,-1));
        return check(dp,locations,start,finish,fuel,n);
    }
};