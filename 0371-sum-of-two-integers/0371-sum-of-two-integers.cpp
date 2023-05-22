class Solution {
public:
    int mod = 1e9+7;
long long binpow(long long a, long long b) {
    if (b <= 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (res * (res * (a)%mod)%mod)%mod;
    else
        return (res * res)%mod;
}
    long long getSum(long long a, long long b) {
       unsigned int carry = (a&b);
       carry = carry<<1;
       int result = a^b;
       if(carry == 0) return result;
       return getSum(result,carry);
    }
};