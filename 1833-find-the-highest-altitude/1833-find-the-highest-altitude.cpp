class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int cnt = 0;
        for(auto &it:gain){
            cnt+=it;
            ans = max(ans,cnt);
        }   
        return ans;
    }
};