class Solution {
public:
    vector<int> ans;
    // std::srand(0);
    Solution(vector<int>& w) {
        
        ans.resize(w.size(),0);
        ans[0] = w[0];
        for(int i = 1;i<ans.size();i++){
            ans[i] = w[i]+ans[i-1];
        }
    }
    
    int pickIndex() {
        int t = rand()%ans[ans.size()-1]+1;
        auto it = lower_bound(ans.begin(),ans.end(),t)-ans.begin();
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */