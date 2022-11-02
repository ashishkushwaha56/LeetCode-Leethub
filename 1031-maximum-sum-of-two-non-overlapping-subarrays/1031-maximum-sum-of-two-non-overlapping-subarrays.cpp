class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstlen, int secondlen) {
        vector<int> pre(nums.size()+1);
        pre[1] = nums[0];
        for(int i = 1;i<nums.size();i++){
            pre[i+1] = pre[i]+nums[i];
        }
        multimap<int,pair<int,int>> mb1,mb2;
        for(int i = firstlen;i<nums.size()+1;i++){
            mb1.insert({pre[i]-pre[i-firstlen],{i-firstlen,i-1}});
        }
        
        for(int i = secondlen;i<nums.size()+1;i++){
            mb2.insert({pre[i]-pre[i-secondlen],{i-secondlen,i-1}});
        }
        
        int ans1 = INT_MIN;
        int ans2 = INT_MIN;
        int t1;
        for(auto &it:mb1){
            ans2 = INT_MIN;
            for(auto &it1:mb2){
                if(it1.second.second<it.second.first or it1.second.first>it.second.second)
                {
                    ans2 = max(ans2,it1.first+it.first);
                }
            }
            if(ans2!=INT_MIN){
                ans1 = max(ans1,ans2);
            }
        }
        return ans1;
        
    }
};