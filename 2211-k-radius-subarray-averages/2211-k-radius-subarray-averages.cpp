class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long ans = 0;
        
        for(int i = 0;i<nums.size() and i<2*k;i++){
            ans+=nums[i];
        }
        
        vector<int> v(nums.size(),-1);
        if(2*k>=nums.size()) return v;
        for(int i = k;i<nums.size()-k;i++){
            ans+=nums[i+k];
            // cout<<i<<endl;
            // cout<<i+k<<endl;
            // cout<<i-k<<endl;
            // cout<<"---------"<<endl;

            v[i]=(ans/(2*k+1));
            ans-=nums[i-k];
        }
        return v;
    }
};