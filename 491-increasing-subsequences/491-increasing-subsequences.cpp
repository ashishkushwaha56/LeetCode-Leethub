class Solution {
public:
    set<vector<int>> ans;
    bool ok = true;
    void f(vector<int> &v,int i,vector<int>&temp){
        if(i>=v.size()){
                ok = true;
               for(int k = 1;k<temp.size();k++){
                   if(temp[k]<temp[k-1]){
                       ok = false;
                       break;
                   }
               }
            if(ok and temp.size()>=2){
               ans.insert(temp); 
            }
            return;
        }
        temp.push_back(v[i]);
        f(v,i+1,temp);
        temp.pop_back();
        f(v,i+1,temp);
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        f(nums,0,temp);
        vector<vector<int>> res;
        for(auto &it:ans){
            res.push_back(it);
        }
        return res;
    }
};