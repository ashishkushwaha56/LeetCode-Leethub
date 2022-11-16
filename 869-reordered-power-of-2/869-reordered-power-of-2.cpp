class Solution {
public:
    set<string> vb;
    void f(){
        long long a = 1;
        string s;
        while(a<=1e10){
            s = to_string(a);
            sort(s.begin(),s.end());
            vb.insert(s);
            a<<=1ll;
        }
    }
    bool reorderedPowerOf2(int n) {
        f();
        string s = to_string(n);
        sort(s.begin(),s.end());
        if(vb.find(s)!=vb.end()) return true;
        return false;
    }
};