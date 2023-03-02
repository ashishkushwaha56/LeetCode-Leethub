class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        // vector<int> v;
        bool ok = true;
        for(int i = 0;i<l.size();i++){
            vector<int> v(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(v.begin(),v.end());
            ok = true;
            for(int j = 0;j<v.size()-1;j++){
                if(v[j+1]-v[j] !=v[1]-v[0]){
                    ok = false;
                    break;
                }
            }
            ans[i] = ok;
        }
        return ans;
        
    }
};