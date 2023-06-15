class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int j = 0;
        int id = 0;
        int cnt = 0;
        while(j<gas.size()){
            if(gas[j]<cost[j] and cnt+gas[j]<cost[j]){
                j++;
                cnt = 0;
                i = j;
                continue;
            }
            cnt+=gas[j];
            cnt-=cost[j];
            if(cnt<0){
                j++;
                i=j;
            }
            else {
                j++;
            }
        }
        if(i == gas.size()) return -1;
        cnt = 0;
        j = i;
        while(true){
            cnt+=gas[j];
            cnt-=cost[j];
            if(cnt<0) return -1;
            j = (j+1)%gas.size();
            if(i == j) return i;
        }
        return -1;
    }
};