class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        pair<int,int> p;
        for(int i = 0;i<mat.size();i++){
            p = {count(mat[i].begin(),mat[i].end(),1),i};
            v.push_back(p);
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
           if(a.first == b.first) return a.second<b.second;
            return a.first<b.first;
        });
        vector<int> ans;
        for(int i= 0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};