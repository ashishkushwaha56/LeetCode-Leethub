class Solution {
public:
    bool isValid(string s) {
        stack<char> sd;
        if(s.size()<3) return false;
        sd.push(s[0]);
        sd.push(s[1]);
        char a,b;
        for(int i = 2;i<s.size();i++){
            if(s[i] == 'c'){
                if(sd.size()>=2){
                    b = sd.top();
                    sd.pop();
                    // a = sd.top();
                    if(sd.top() == 'a' and b == 'b'){
                        sd.pop();
                    }
                    else{
                        sd.push(b);
                        sd.push(s[i]);
                    }
                }
                else{
                    sd.push(s[i]);
                }
            }
            else{
                sd.push(s[i]);
            }
        }
        return sd.size()==0;
    }
};