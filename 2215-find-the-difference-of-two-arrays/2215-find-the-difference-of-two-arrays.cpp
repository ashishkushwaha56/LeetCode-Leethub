class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a(nums1.begin(),nums1.end());
        unordered_set<int> b(nums2.begin(),nums2.end());
        // int c = 0,d =0;
        vector<int> c,d;
        for(auto &it:a){
            if(b.find(it) == b.end()) c.push_back(it);
        }
        for(auto &it:b){
            if(a.find(it)==a.end()) d.push_back(it);
        }
        return {c,d};
    }
};