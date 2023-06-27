class Solution {
public:
    bool check(long long n,int t){
        int a = 0;
        while(n){
            a+=n%10;
            n/=10;
        }
        return (a<=t);
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0;
        if(check(n,target)) return 0ll;
        long long jj = 10;
        long long d = n;
        while(!check(d,target)){
            long long dig = d%jj;
            d+=(jj-dig);
            jj*=10;
        }
        return d-n;
    }
};