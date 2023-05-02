class Solution {
public:
    int commonFactors(int a, int b) {
        int maxe = max(a,b);
        int ans = 1;
        for(int i = 2;i<=max(a,b);i++){
            if(a%i==0 and b%i == 0){
                // ans+=2;
                // if(i*i == maxe) ans--;
                ans++;
            }
        }
        return ans;
    }
};