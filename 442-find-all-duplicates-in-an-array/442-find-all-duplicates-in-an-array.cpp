class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mb;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(mb.find(nums[i])!=mb.end()){
                ans.push_back(nums[i]);
            }
            mb[nums[i]]++;
        }
        return ans;
    }
};