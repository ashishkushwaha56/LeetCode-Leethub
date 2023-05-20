class Solution {
public:
    bool check(vector<int>&nums,int k,int mid){
        int i=0;
        int cnt = 0;
        while(i<nums.size() and k){
            if(nums[i]>mid) return false;
            cnt+=nums[i];
            
            if(cnt>mid){
                k--;
                cnt = nums[i];
            }
            if(i==nums.size()-1){
                if(cnt>0 and k == 0) return false;
            }
            i++;
        }
        if(i == nums.size()) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        int r = 1e9+1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(nums,k,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};