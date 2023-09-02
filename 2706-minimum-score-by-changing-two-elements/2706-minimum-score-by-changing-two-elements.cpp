class Solution {
public:
    int minimizeSum(vector<int>& v) {
        if(v.size()<=3) return 0;
        sort(v.begin(),v.end());
        // cout<<v[n-1]-v[2]<<endl;
        // cout<<v[n-1]-v[1]<<endl;
        // cout<<v[n-1]-v[0]<<endl;
        // cout<<v[n-3]-v[0]<<endl;
        // cout<<v[n-2]-v[0]<<endl;
        // cout<<v[n-2]-v[1]<<endl;
        // ans = abs(nums[0]-nums[nums.size()-3]);
        //     }
        //     else if(i==1){
        //         ans = min(ans,abs(nums[1]-nums[nums.size()-2]));
        //         if(nums.size()-i-1>=2){
        //             ans = min(ans,abs(nums[0]-nums[nums.size()-3]));
        //         }
        //     }
        //     else if(i>1 or i<nums.size()-2){
        //         ans = min(ans,abs(nums[2]-nums[nums.size()-1]));
        //         ans = min(ans,abs(nums[1]-nums[nums.size()-2]));
        //         ans = min(ans,abs(nums[0]-nums[nums.size()-3]));
        //     }
        //     else if(i == nums.size()-2){
        //         ans = min(ans,abs(nums[1]-nums[nums.size()-2]));
        //         // if(nums.size()-i-1>=2){
        //         //     ans = min(ans,abs(nums[1]-nums[nums.size()-3]));
        //         // }
        //     }
        //     else if(i==nums.size()-1){
        //         ans = min(ans,abs(nums[2]-nums[i]));
        int n = v.size();
        return min({v[n-1]-v[2],v[n-1]-v[1],v[n-3]-v[0],v[n-1]-v[0],v[n-2]-v[0],v[n-2]-v[1]});
    }
};