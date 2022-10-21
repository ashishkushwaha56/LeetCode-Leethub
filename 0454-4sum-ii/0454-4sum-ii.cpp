class Solution {
public:
    unordered_map<int,int> mb;
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        for(auto &it:nums3){
            for(auto &it1:nums4){
                mb[it+it1]++;
            }
        }
        int ans = 0;
        int t = 0;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                t = -(nums1[i]+nums2[j]);
                if(mb.find(t)!=mb.end()){
                    ans+=mb[t];
                }
            }
        }
        return ans;
    }
};