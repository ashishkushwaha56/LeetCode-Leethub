class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int a = 0,b = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]&1) a++;
            else b++;
        }
        int ans =max(a,b);
        int cnt = 0;
        int i = 0;
        int flag = -1;
        while(i<nums.size()){
            if(i==0){
                if(nums[i]&1){
                    flag = 1;
                }
                else{
                    flag = 0;
                }
                cnt++;
            }
            else{
                if(flag==1 and !(nums[i]&1)){
                    flag = 0;
                    cnt++;
                }
                else if(flag==0 and (nums[i]&1)){
                    flag = 1;
                    cnt++;
                }
                else{
                    i++;
                    continue;
                }
            }
            i++;
        }
        return max(ans,cnt);
    }
};