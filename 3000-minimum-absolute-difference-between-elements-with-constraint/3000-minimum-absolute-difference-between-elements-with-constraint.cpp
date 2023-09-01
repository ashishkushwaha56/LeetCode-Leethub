class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if(x == 0) return 0;
        int ans = INT_MAX;
        map<int,int> mb;
        int i = x;
        while(i<nums.size()){
            mb[nums[i-x]]++;
            auto it = mb.lower_bound(nums[i]);
            if(it!=mb.end()){
                ans = min(ans,abs((*it).first-nums[i]));
            }
            if(it!=mb.begin()){
                it--;
                ans = min(ans,abs((*it).first-nums[i]));
            }
            i++;
        }
        return ans;
    }
};