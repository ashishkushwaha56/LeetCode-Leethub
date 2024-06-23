class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mb;
        int i = 0,j = 0;
        int n = nums.size();
        int ans = 1;
        while(j<n){
            mb[nums[j]]++;
            int maxi = (*(--mb.end())).first;
            int mini = (*(mb.begin())).first;
            
            while(i<j and maxi-mini>limit){
                mb[nums[i]]--;
                if(mb[nums[i]]==0) mb.erase(nums[i]);
                maxi = (*(--mb.end())).first;
                mini = (*(mb.begin())).first;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};