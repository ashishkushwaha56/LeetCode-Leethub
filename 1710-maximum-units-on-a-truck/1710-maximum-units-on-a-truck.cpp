class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        int n = box.size();
        int ans = 0;
        int count = 0;
        sort(box.begin(),box.end(),[&](vector<int>&a,vector<int>&b){
           return a[1]>b[1]; 
        });
        for(int i = 0;i<n;i++){
            ans+=min(truckSize-count,box[i][0])*box[i][1];
            count+=min(truckSize-count,box[i][0]);
        }
        return ans;
    }
};