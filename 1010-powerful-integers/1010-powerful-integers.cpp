class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int a,d;
        if(bound<=1) return {};
        if(x == 1){
            a = bound;
        }
        else{
            a = log(bound)/log(x);
        }
        // int 
        if(y == 1){
            d = bound;
        }
        else{
            d = log(bound)/log(y);
        }
        if(x == 1 and y == 1){
            if(bound>=2){
                return {2};
            }
            return {};
        }
        // int d = log(bound)/log(y);
        int xa = 1;
        int yd = 1;
        set<int> s;
        for(int i = 0;i<=a;i++){
            yd = 1;
            for(int j = 0;j<=d;j++){
                if(yd+xa<=bound)
                s.insert(yd+xa);
                yd*=y;
            }
            xa*=x;
        }
        vector<int> ans;
        for(auto &it:s){
            ans.push_back(it);
        }
        return ans;
    }
};