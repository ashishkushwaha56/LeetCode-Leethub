class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt =1;
        if(nums.size() == 0) return 0;
        int ans = cnt;
        sort(nums.begin(),nums.end());
        vector<int> temp = {nums[0]};
        for(int i = 1;i<nums.size();i++){
            if(temp.back()+1 == nums[i]){
                temp.push_back(nums[i]);
                cnt++;
            }
            else if(temp.back()+1!=nums[i] and temp.back()!=nums[i]){
                temp.clear();
                ans = max(ans,cnt);
                temp.push_back(nums[i]);
                cnt = 1;
            }
            ans= max(ans,cnt);
        }
        return ans;
    }
};