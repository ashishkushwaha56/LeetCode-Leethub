class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        set<int> a,b;
        int cnt = 0;
        for(int i = 0;i<A.size();i++){
            a.insert(A[i]);
            b.insert(B[i]);
            cnt = 0;
            for(auto &it:a){
                if(b.find(it)!=b.end()){
                    cnt++;
                }
                
            }
            ans[i] = cnt;
        }
        return ans;
    }
};