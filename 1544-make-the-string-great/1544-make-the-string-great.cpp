class Solution {
public:
    string makeGood(string s) {
        stack<char> temp;
        for(int i = 0;i<s.size();i++){
            if(temp.empty()){
                temp.push(s[i]);
            }
            else{
                if(s[i] >='A' and s[i]<='Z'){
                    if(temp.top() == 'a'+s[i]-'A'){
                        temp.pop();
                    }
                    else{
                        temp.push(s[i]);
                    }
                }
                else{
                    if(temp.top() == 'A'+s[i]-'a'){
                        temp.pop();
                    }
                    else{
                        temp.push(s[i]);
                    }
                }
            }
        }
        string ans = "";
        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};