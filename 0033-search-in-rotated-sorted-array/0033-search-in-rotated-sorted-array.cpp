class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int x = nums[nums.size()-1];
        int pivot = l;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>x){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        pivot=l;
        l = pivot;
        // cout<<pivot<<endl;
        // r = (l-1+nums.size())%nums.size();
        // cout<<r<<endl;
        // while(r!=l){
        //     int mid;
        //     if(r>=l){
        //         mid = l+(r-l)/2;
        //     }
        //     else{
        //         int a = 0;
        //         int b = nums.size()-l+r;
        //         mid = a+(b-a)/2;
        //     }
        //     cout<<"mid = "<<mid<<endl;
        //     int d = (pivot+mid)%nums.size();
        //     cout<<"d = "<<d<<endl;
        //     if(nums[d] == target) return d;
        //     else if(nums[d]>target){
        //         r = (d-1+nums.size())%nums.size();
        //     }
        //     else{
        //         l = (d+1+nums.size())%nums.size();
        //     }
        // }
        if(target == nums[nums.size()-1]) return nums.size()-1;
        else if(target>nums[nums.size()-1]){
            l= 0;
            r = pivot-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid]<target){
                    l = mid+1;
                }
                else r = mid-1;
            }
        }
        else{
            l= pivot;
            r = nums.size()-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid]<target){
                    l = mid+1;
                }
                else r = mid-1;
            }
        }
        return -1;
    }
};