class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        int a = 0,b = 0;
        for(int i = 0;i<s.size();i++){
            if(i&1){
                a = a*10+(s[i]-'0');
            }
            else b= b*10+(s[i]-'0');
        }
        return a+b;
    }
};