class Solution {
public:
    int check(vector<int>&nums){
        vector<int> temp;
        int a;
        for(int i = 0;i<nums.size()-1;i++){
            a = __gcd(nums[i],nums[i+1]);
            if(a == 1) return 1;
            temp.push_back(a);
        }
        return 1+check(temp);
    }
    int minOperations(vector<int>& nums) {
        // bool ok = false;
        int c = 0;
        for(int i = 0;i<nums.size();i++){
            c=__gcd(nums[i],c);
        }
        if(c!=1) return -1;
        int cnt= count(nums.begin(),nums.end(),1);
        if(cnt>0){
            return nums.size()-cnt;
        }
        int res = check(nums);
        return nums.size()-1+res;
    }
};