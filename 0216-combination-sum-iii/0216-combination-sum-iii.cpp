class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    vector<int>temp;
    void dfs(vector<int>&v,int i,int k,int n,vector<int>&temp){
        if(temp.size() == k){
            if(n == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(i == v.size()){
            if(n == 0 and temp.size() == k){
                ans.push_back(temp);
            }
            return;
        }
        if(n-v[i]>=0){
            temp.push_back(v[i]);
            dfs(v,i+1,k,n-v[i],temp);
            temp.pop_back();
        }
        dfs(v,i+1,k,n,temp);

        // if(i == v.size())
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        for(int i = 1;i<=9;i++){
            v.push_back(i);
        }
        dfs(v,0,k,n,temp);
        return ans;
    }
};