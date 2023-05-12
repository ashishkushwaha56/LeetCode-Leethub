class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mb;
        int i = 0;
        while(i<k){
            mb[nums[i]]++;
            i++;
        }
        vector<int> ans(nums.size()-k+1);
        while(i<nums.size()){
            auto it = mb.end();
            it--;
            // mb[nums[i]]++;
            ans[i-k] = (*it).first;
            mb[nums[i-k]]--;
            if(mb[nums[i-k]] == 0) mb.erase(nums[i-k]);
            mb[nums[i]]++;
            i++;
        }
        auto it1 = mb.end();
            it1--;
            // mb[nums[i]]++;
            ans[i-k] = (*it1).first;
        return ans;
    }
};