class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        int d = (n+m)/2;
        int l = 0;
        int r = 0;
        int last = 0;
        vector<int> temp;
        while(l<n and r<m and (l+r)<=d){
            if(nums1[l]<nums2[r]){
                temp.push_back(nums1[l++]);
            }
            else{
                temp.push_back(nums2[r++]);
            }
        }
        while(l<n and (l+r)<=d){
            temp.push_back(nums1[l++]);
        }
        while(r<m and (l+r)<=d){
            temp.push_back(nums2[r++]);
        }
        if(!((n+m)&1)){
            ans = (double)(temp[temp.size()-1]+temp[temp.size()-2])/2;
        }      
        else{
            ans = (double)(temp[temp.size()-1]);
        }
        return ans;
    }
};