class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void check(int &target,int t,int &sum,vector<int> &temp){
        if(sum>target) return;
        if(sum == target){
            
            ans.push_back(temp);
            return;
        }
        for(int i = t;i<v.size();i++){
            if(i>t and v[i] == v[i-1]) continue;
            temp.push_back(v[i]);
            sum+=v[i];
            check(target,i+1,sum,temp);
            sum-=v[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        v = candidates;
        vector<int> temp;
        int sum = 0;
        int i = 0;
        check(target,i,sum,temp);
        return ans;
    }
};