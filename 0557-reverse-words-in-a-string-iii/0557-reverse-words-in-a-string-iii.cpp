class Solution {
public:
    string reverseWords(string s) {
        string a = "";
        vector<string> v;
        for(auto &it:s){
            if(it == ' '){
                if(a.size()>0){
                    v.push_back(a);
                    a = "";
                }
            }
            else{
                a+=it;
            }
        }
        if(a.size()>0){
            v.push_back(a);
        }
        string ans = "";
        for(auto &it:v){
            reverse(it.begin(),it.end());
            ans+=it;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};