class Solution {
public:
    bool isFascinating(int n) {
        string ans = to_string(n);
        ans+=to_string(2*n);
        ans+=to_string(3*n);
        vector<int> v(10);
        for(auto &it:ans){
            if(it=='0') return false;
            v[it-'0']++;
        }
        for(int i = 1;i<10;i++){
            if(v[i]!=1) return false;
        }
        return true;
    }
};