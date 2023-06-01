class Solution {
public:
    bool checkRecord(string s) {
        int late = 0;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'L') late++;
            else if(s[i] == 'A'){
                late = 0;
                cnt++;
            }
            else{
                late = 0;
            }
            if(late>=3 or cnt==2) return false;
        }
        return true;
    }
};