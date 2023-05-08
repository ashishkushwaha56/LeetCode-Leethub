class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int cnt1 = 0;
        for(int i = 0;i<arr1.size();i++){
            cnt1=(cnt1^arr1[i]);
        }
        int ans = 0;
        // int cnt2= 0 ;
        for(int  i = 0;i<arr2.size();i++){
            ans = (ans^(cnt1&arr2[i]));
        }
        return ans;
    }
};