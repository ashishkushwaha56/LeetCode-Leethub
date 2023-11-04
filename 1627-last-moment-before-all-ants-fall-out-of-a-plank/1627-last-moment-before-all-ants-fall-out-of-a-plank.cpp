class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;
        for(auto &it:left){
            time = max(time,it);
        }
        for(auto &it:right){
            time = max(time,n-it);
        }
        return time;
    }
};