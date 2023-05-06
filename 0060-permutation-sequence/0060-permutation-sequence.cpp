class Solution {
public:
    vector<string> ans;
    void f(int n, vector<int>&v,string &s){
        if(s.size()==n) {ans.push_back(s); return;}
        for(int i=1;i<=n;i++){
            if(v[i-1] == true){
                s+=(i+'0');
                v[i-1] = false;
                f(n,v,s);
                v[i-1] = true;
                s.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        string s = "";
        vector<int> v(n,true);
        for(int i=1;i<=n;i++){
            if(v[i-1] == true){
                s+=(i+'0');
                v[i-1] = false;
                f(n,v,s);
                v[i-1] = true;
                s.pop_back();
            }
        }
        return ans[k-1];
    }
};