class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans =0;
        unordered_map<int,int>mb;
        for(int i = 0;i<nums.size();i++){
            mb[nums[i]]++;
            if(mb.find(nums[i]-1)!=mb.end()){
                ans = max(ans,mb[nums[i]-1]+mb[nums[i]]);
            }
            if(mb.find(nums[i]+1)!=mb.end()){
                ans = max(ans,mb[nums[i]+1]+mb[nums[i]]);
            }
        }
        return ans;
    }
};