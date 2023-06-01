class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int last = 1;
        vector<int> ans;
        set<int> s;
        for(int i = 1;i<nums.size()+1;i++){
            s.insert(i);
        }
        for(auto &it:nums){
            if(s.find(it)!=s.end()) s.erase(it);
        }
        for(auto &it:s){
            ans.push_back(it);
        }
        return ans;
    }
};