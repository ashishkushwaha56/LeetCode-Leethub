class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while(maxDoubles){
            if(target>1 and target&1){
                target--;
                cnt++;
            }
            else{
                target>>=1;
                maxDoubles--;
                cnt++;
            }
            if(target<=1){
                break;
            }
            
        }
        cnt+=target-1;
        return cnt;
    }
};