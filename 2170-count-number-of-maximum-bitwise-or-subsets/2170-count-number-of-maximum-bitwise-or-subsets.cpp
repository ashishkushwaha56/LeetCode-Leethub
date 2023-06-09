class Solution {
public:
    int check(vector<int>&nums,int i,int a,int &cnt){
        if(i==nums.size()){
            if(a == cnt)return 1;
            return 0;
        }
        return(check(nums,i+1,a|nums[i],cnt)+check(nums,i+1,a,cnt));
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        for(auto &it:nums){
            cnt = cnt|it;
        }
        // int a;
        // for(int i = 0;i<nums.size();i++){
        //     a = 0;
        //     for(int j = i;j<nums.size();j++){
        //         a = a|nums[j];
        //         if(a == cnt) ans++;
        //     }
        // }
        return check(nums,0,0,cnt);
    }
};