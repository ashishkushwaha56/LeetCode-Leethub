class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxe = -1;
        int a;
        for(int i = arr.size()-1;i>=0;i--){
            a = arr[i];
            arr[i] = maxe;
            maxe = max(maxe,a);
        }
        return arr;
    }
};