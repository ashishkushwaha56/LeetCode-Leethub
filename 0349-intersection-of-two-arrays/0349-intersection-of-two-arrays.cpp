class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto &it:nums1){
            s.insert(it);
        }
        set<int> sd;
        vector<int> ans;
        for(auto &it:nums2){
            if(s.find(it)!=s.end() and sd.find(it)==sd.end()) {
                ans.push_back(it);
                sd.insert(it);
            }
            
        }
        return ans;
    }
};