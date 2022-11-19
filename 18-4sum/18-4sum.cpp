class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        long long c;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-3;i++){
            for(int j = i+1;j<n-2;j++){
                c = (long long)target-nums[i] -nums[j];
                int l = j+1;
                int r = n-1;
                while(l<r){
                    if(nums[l]+nums[r] == c) {
                        ans.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                    }
                    else if(nums[l]+nums[r]<c){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                
            }
        }
        vector<vector<int>> res;
        for(auto &it:ans){
            res.push_back(it);
        }
        return res;
    }
};