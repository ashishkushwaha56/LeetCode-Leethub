class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m+n);
        int i = 0;int j = 0;
        while(i<m and j<n){
            if(nums1[i]<=nums2[j]){
                v[i+j] = nums1[i];
                i++;
            }
            else{
                v[i+j] = nums2[j];
                j++;
            }
        }
        while(i<m){
            v[i+j] = nums1[i];
            i++;
        }
        while(j<n){
            v[i+j] = nums2[j];
            j++;
        }
        nums1 = v;
    }
};