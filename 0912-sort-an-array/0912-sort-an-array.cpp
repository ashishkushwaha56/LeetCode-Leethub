class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(),a.end());
        return a;
    }
};