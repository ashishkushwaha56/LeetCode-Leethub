class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum<x) return -1;
        unordered_map<int,int> mb;
        int t = sum-x;
        mb[0] = -1;
        int cnt = 0;
        int ans = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            cnt+=nums[i];
            if(mb.find(cnt) == mb.end()){
                mb[cnt] = i;
            }
            if(mb.find(cnt-t)!=mb.end()){
                ans = min(ans,(int)(mb[cnt-t]+1+nums.size()-1-i));
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};