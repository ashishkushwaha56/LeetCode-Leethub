class Solution {
public:
    int countDigits(int num) {
        string a = to_string(num);
        int cnt =0;
        for(auto &it:a){
            cnt+=(num%(it-'0') == 0);
        }
        return cnt;
    }
};