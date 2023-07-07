class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while(i<s.size()){
            int d = s.size()-i;
            if(d<=k){
                reverse(s.begin()+i,s.begin()+i+d);
            }
            else{
                reverse(s.begin()+i,s.begin()+i+k);
            }
            i+=(2*k);
        }
        return s;
    }
};