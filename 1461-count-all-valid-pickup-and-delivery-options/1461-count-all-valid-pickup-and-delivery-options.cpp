class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) {
        if(n == 1) return 1;
        long long ans = ((long long)countOrders(n-1)%mod*((2*n-1)*n)%mod)%mod;
        return ans;
    }
};