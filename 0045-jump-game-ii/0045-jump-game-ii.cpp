class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(i<n-1){
            int maxlen = 0;
            j = i+nums[i];
            if(j>=n-1){ ans++; break;}
            int t = j;
            int k = j;
            while(t>i){
                if(maxlen<nums[t]+t-i){
                    maxlen = nums[t]+t-i;
                    k = t;
                }
                t--;  
            }
            ans++;
            i = k;
        }
        return ans;
    }
};