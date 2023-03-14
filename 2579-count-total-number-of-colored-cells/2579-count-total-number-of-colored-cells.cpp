class Solution {
public:
    long long coloredCells(int n) {
        long long cnt = 0;
        long long ans = 0;
        long long increament = 4;
        bool flag = 0;
        while(n>0){
            // ans+=cnt;
            if(!flag){
                cnt+=1;
                flag = 1;
                n--;
                continue;
                
            }
            cnt+=increament;
            increament+=4;
            n--;
        }
        return cnt;
    }
};