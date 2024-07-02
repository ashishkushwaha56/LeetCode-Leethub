class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mb,md;  
        for(auto &it:nums1){
            mb[it]++;
        }
        vector<int>::iterator it = nums2.begin();
        for(;it!=nums2.end();it++){
            md[*it]++;
        }
        int d;vector<int> ans;
        for(auto &it:mb){
            if(md.find(it.first)!=md.end()){
                d =min(it.second,md[it.first]);
                while(d-->0){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};