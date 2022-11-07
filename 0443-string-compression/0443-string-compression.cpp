class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        char c = chars[0];
        int cnt = 1;
        for(int i = 1;i<chars.size();i++){
            if(chars[i]!=chars[i-1]){
                s+=chars[i-1];
                if(cnt>1){
                    s+=to_string(cnt);
                }
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        s+=chars[chars.size()-1];
        if(cnt>1){
            s+=to_string(cnt);
        }
        for(int i = 0;i<s.size();i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};