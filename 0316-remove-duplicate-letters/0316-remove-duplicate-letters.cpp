class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mb;
        unordered_map<char,bool> bs;
        string ans = "";
        stack<int> sd;
        for(auto &it:s){
            mb[it]++;
            bs[it] = false;
        }
        for(int i = 0;i<s.size();i++){
            mb[s[i]]--;
            if(bs[s[i]]) continue;
            while(!sd.empty() and s[sd.top()]> s[i] and mb[s[sd.top()]]>0){
                bs[s[sd.top()]] = false;
                sd.pop();
            }
            sd.push(i);
            bs[s[i]] = true;
        }
        while(!sd.empty()){ ans+=s[sd.top()]; sd.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};