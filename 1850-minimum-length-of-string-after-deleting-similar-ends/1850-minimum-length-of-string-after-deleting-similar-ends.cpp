class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return r-l+1;
            }
            char a = s[l];
            // char b = s[r];
            while(l<r and s[l] == a){
                l++;
            }
            if(r == l) return 0;
            while(l<r and s[r] == a){
                r--;
            }
            if(r == l) return 1;
            // l++;r--;
        }
        if(r<l){
            return 0;
        }
        return r-l+1;
    }
};