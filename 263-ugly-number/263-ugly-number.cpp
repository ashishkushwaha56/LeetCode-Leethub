class Solution {
public:
    vector<int> a;
    
    bool isUgly(int n) {
        if(n<=0)return false;
        int t = n;
        for(long long i = 2;i*i<=n;i++){
            if(t%i == 0){
                a.push_back(i);
                while(t%i == 0){
                    t = t/i;
                }
            }
        }
        if(t>1) a.push_back(t);
        for(int i = 0;i<a.size();i++){
            if(a[i]!=2 and a[i]!=3 and a[i]!=5) return false;
        }
        return true;
    }
};