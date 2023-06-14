class Solution {
public:
    long long ans = LLONG_MIN;
    void check(vector<int>&nums,int i,vector<int>&temp){
        if(i == nums.size()){
            if(temp.size() == 0) return;
            long long a = temp[0];
            for(int i = 1;i<temp.size();i++){
                a*=temp[i];
            }
            ans = max(ans,a);
            return;
        }
        temp.push_back(nums[i]);
        check(nums,i+1,temp);
        temp.pop_back();
        check(nums,i+1,temp);
    }
    long long maxStrength(vector<int>& nums) {
        vector<int>temp;
        check(nums,0,temp);
        return ans;
    }
};