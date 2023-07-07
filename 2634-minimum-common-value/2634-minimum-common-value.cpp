class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mb1,mb2;
        for(auto &it:nums1){
            mb1[it]++;
        }
        for(auto &it:nums2){
            mb2[it]++;
        }
        int ans= 0;
        for(auto &it:nums1){
            if(mb1.find(it)!=mb1.end() and mb2.find(it)!=mb2.end()) return it;
            // mb1[it]--;
            // if(mb1[it]==0) mb1.erase(it);
        }
        // return ans;
        return -1;
    }
};