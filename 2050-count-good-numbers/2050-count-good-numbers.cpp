class Solution {
public:
    int mod = 1e9+7;
    long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = (binpow(a, b / 2))%mod;
    if (b % 2)
        return (res * (res * (a)%mod)%mod)%mod;
    else
        return (res * (res)%mod)%mod;
}
    
    // int helper(long long n,long long i){
    //     if(i == n) return 1;
    //     if(i&1){
    //         int a = helper(n,i+1)%mod;
    //         return (4*a)%mod;
    //     }
    //     int a =helper(n,i+1)%mod;
    //     return (5*a)%mod;
    // }
    int countGoodNumbers(long long n) {
        long long d,g;
        if(n&1){
            d = n/2+1;
        }
        else
            d = n/2;
        g = n/2;
        long long a = binpow(5,d);
        long long b = binpow(4,g);
        return (a*b)%mod;
    }
};