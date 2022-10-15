class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n,-1),vis(n);
        vector<int> left;
        vector<pair<int,int>> temp;
        for(int i = 0;i<n;i++){
            temp.push_back({nums2[i],i});
        }
        
        sort(temp.begin(),temp.end());
        sort(nums1.begin(),nums1.end());
        for(int i = 0;i<n;i++){
            pair<int,int> p = {nums1[i],0};
            auto it = upper_bound(temp.begin(),temp.end(),p);
            if(it==temp.begin()){
                if((*it).first<nums1[i] and !vis[(*it).second]){
                    vis[(*it).second] = 1;
                    ans[(*it).second] = nums1[i];
                }
                else{
                    left.push_back(nums1[i]);
                }
                continue;
            }
            it--;
            while(it!=temp.begin()){
                if((*it).first<nums1[i] and !vis[(*it).second]){
                    break;
                }
                it--;
            }
            if((*it).first<nums1[i] and !vis[(*it).second]){
                vis[(*it).second] = 1;
                ans[(*it).second] = nums1[i];
            }
            else{
                left.push_back(nums1[i]);
            }
        }
        for(int i = 0;i<n;i++){
            if(ans[i] == -1){
                ans[i] = left.back();
                left.pop_back();
            }
        }
        return ans;
    }
};