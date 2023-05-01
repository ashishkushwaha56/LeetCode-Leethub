class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<pair<int,int>,int> mb;
        map<int,pair<int,int>> vb;
        int m= mat.size();
        int n=mat[0].size();
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[i].size();j++){
                vb[mat[i][j]] = {i,j};
            }
        }
        
        for(int i = 0;i<arr.size();i++){
            mb[{vb[arr[i]].first,0}]++;
            mb[{vb[arr[i]].second,1}]++;
            if(mb[{vb[arr[i]].first,0}] == n){
                return i;
            }
            if(mb[{vb[arr[i]].second,1}] == m) return i;
        }
        return 0;
    }
};