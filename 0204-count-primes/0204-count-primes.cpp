class Solution {
public:

    int countPrimes(int n) {
        if(n<=2) return 0;
        int cnt = 1;
        vector<int> is_prime(n+1,1);
        for(int i = 3;i*i<=n;i+=2){
            if(is_prime[i]){
                cnt++;
                for(int j = i*i;j<=n;j+=i){
                    is_prime[j] = 0;
                }
            }
        }
        int j;
        if(((int)sqrt(n)+1)&1){
            j = sqrt(n)+1;
        }
        else{
            j = sqrt(n)+2;
        }
        for(;j<n;j+=2){
            if(is_prime[j]) cnt++;
        }
        return cnt;
    }
};