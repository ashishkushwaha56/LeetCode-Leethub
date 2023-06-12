class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto it1 = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        auto it2 = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(it1 == it2) return {};
        vector<int> ans;
        for(int i = it1;i<it2;i++){
            ans.push_back(i);
        }
        return ans;
    }
};