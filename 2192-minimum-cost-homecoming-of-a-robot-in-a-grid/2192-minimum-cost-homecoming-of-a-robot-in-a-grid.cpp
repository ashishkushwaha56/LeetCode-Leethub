class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        // int start_row = min(startPos[0],homePos[0]);
        // int end_row = max(startPos[0],homePos[0]);
        // int start_col = min(startPos[1],homePos[1]);
        // int end_col = max(startPos[1],homePos[1]);
        if(startPos[0]>=homePos[0]){
            for(int i = startPos[0]-1;i>=homePos[0];i--){
                ans+=rowCosts[i];
            }
        }
        if(startPos[0]<homePos[0]){
            for(int i = startPos[0]+1;i<=homePos[0];i++){
                ans+=rowCosts[i];
            }
        }
        if(startPos[1]>=homePos[1]){
            for(int i = startPos[1]-1;i>=homePos[1];i--){
                ans+=colCosts[i];
            }
        }
        if(startPos[1]<homePos[1]){
            for(int i = startPos[1]+1;i<=homePos[1];i++){
                ans+=colCosts[i];
            }
        }
        return ans;
    }

};