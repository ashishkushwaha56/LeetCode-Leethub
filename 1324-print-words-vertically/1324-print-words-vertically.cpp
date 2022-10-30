class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        string a;
        vector<pair<string,int>> temp;
        a = "";
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                temp.push_back({a,cnt});
                a = "";
                cnt = 0;
                continue;
            }
            cnt++;
            a+=s[i];
        }
        temp.push_back({a,cnt});
        
        int len = 0;
        for(auto &it:temp){
            len = max(len,it.second);
        }
        int j = 0;
        while(j<len){
            a = "";
            for(auto &it:temp){
                if(j>=it.second){
                   a+=' '; 
                }
                else{
                    a+=it.first[j];
                }
            }
            while(!a.empty() and a.back() == ' '){
                a.pop_back();
            }
            ans.push_back(a);
            j++;
        }
        return ans;
    }
};