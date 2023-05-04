class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;
        for(int i =0 ;i<nums.size();i++){
            while(!s.empty() and nums[i]<s.top() and s.size()-1+nums.size()-i>=k){
                s.pop();
            }
            if(s.size()<k){
                s.push(nums[i]);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};