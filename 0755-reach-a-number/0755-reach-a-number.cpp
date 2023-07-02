class Solution {
public:
    int reachNumber(int target) {
        int cnt  = 0;
        int d = abs(target);
        int ans = 0;
        while(ans<d){
            cnt++;
            ans+=cnt;
            while((d-ans)&1){
                cnt++;
                ans+=cnt;
            }
        }
        return cnt;
    }
};