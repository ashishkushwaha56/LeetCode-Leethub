class Solution {
public:
void merge(vector<int>&nums,int l, int mid,int r,int &ans){
        int j = mid+1;
        for(int i = l;i<=mid;i++){
            while(j<=r and nums[i]>(long long)2*nums[j]){
                j++;
            }
            ans+=(j-mid-1);
        }
        vector<int> temp(r-l+1,0);
        int k =0 ;
        int i = l;
        j = mid+1;
        while(i<=mid and j<=r){
            if(nums[i]<=nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        while(j<=r){
            temp[k++] = nums[j++];
        }
        j = 0;
        for(int i = l;i<=r;i++){
            nums[i] = temp[i-l];
        }
        
    }
    void mergesort(vector<int>&nums,int l, int r,int &ans){
        if(l<r){
            int mid = l+(r-l)/2;
            mergesort(nums,l,mid,ans);
            mergesort(nums,mid+1,r,ans);
            merge(nums,l,mid,r,ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergesort(nums,0,nums.size()-1,ans);
        return ans;
    }
};