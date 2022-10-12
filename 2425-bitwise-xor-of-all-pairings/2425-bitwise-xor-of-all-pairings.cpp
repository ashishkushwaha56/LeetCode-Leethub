class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()-count(nums1.begin(),nums1.end(),0);
        int m = nums2.size()-count(nums2.begin(),nums2.end(),0);
      unordered_map<int,int> v1,v2;
        int a1 = 0,b1 = 0;
        for(int i = 0;i<n;i++){
            v1[nums1[i]]++;
            a1^=nums1[i];
        }
        for(int i = 0;i<m;i++){
            v2[nums2[i]]++;
            b1^=nums2[i];
        }
        int ans = 0;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i] ==0){
                ans^=b1;
                continue;
            }
            if(v2.find(nums1[i])!=v2.end()){
                if(((m-v2[nums1[i]])&1)) ans^=nums1[i];
            }
            else{
                if((m&1)) ans^=nums1[i];
            }
        }
        for(int i = 0;i<nums2.size();i++){
            if(nums2[i] ==0){
                ans^=a1;
                continue;
            }
            if(v1.find(nums2[i])!=v1.end()){
                if(((n-v1[nums2[i]])&1)) ans^=nums2[i];
            }
            else{
                if((n&1)) ans^=nums2[i];
            }
        }
        return ans;
    }
};