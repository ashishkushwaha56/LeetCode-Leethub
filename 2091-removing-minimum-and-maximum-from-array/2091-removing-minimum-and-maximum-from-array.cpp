class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int maxm = nums[0];
        int minm = nums[0];
        for(int i = 0;i<nums.size();i++){
            if(maxm<nums[i]){
                maxm = nums[i];
                l = i;
            }
            if(minm>nums[i]){
                minm=nums[i];
                r = i;
            }
        }
        if(l>r) swap(l,r);
        int a = max(l,r)+1;
        int b = nums.size()-min(l,r);
        int c = l+1+nums.size()-r;
        return (min(a,min(b,c)));
    }
};