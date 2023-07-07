class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        set<int> ans;
        for(int j = 0;j<nums[0].size();j++){
            ans.insert(nums[0][j]);
        }
        set<int> b;
        for(int i =1;i<nums.size();i++){
            b.clear();
            for(int j=0;j<nums[i].size();j++){
                if(ans.find(nums[i][j])!=ans.end()){
                    b.insert(nums[i][j]);
                }
            }
            ans = b;
        }
        cout<<ans.size()<<endl;
        vector<int> d(ans.begin(),ans.end());
        return d;
    }
};