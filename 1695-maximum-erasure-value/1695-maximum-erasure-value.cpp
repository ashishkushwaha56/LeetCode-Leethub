class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      vector<int> pre(nums.size()+1);
        pre[1] = nums[0];
        for(int i = 1;i<nums.size();i++){
            pre[i+1] = pre[i]+nums[i];
        }
        unordered_map<int,int> mb;
        int l = 0;
        int ans = nums[0];
        for(int i = 0;i<nums.size();i++){
            if(mb.find(nums[i])!=mb.end()){
                if(l<=mb[nums[i]]){
                    l = mb[nums[i]]+1;
                }
            }
            mb[nums[i]] = i;
            ans = max(ans,pre[i+1]-pre[l]);
        }
        return ans;
    }
};