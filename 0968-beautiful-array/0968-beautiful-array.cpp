class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};
        while(ans.size()<n){
            vector<int>temp;
            for(auto &it:ans){if(it*2-1<=n) temp.push_back(it*2-1);}
            for(auto &it:ans){if(it*2<=n) temp.push_back(it*2);}
            ans = temp;
        }
        return ans;
    }
};