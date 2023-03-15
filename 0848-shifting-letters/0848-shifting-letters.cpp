class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long cnt = accumulate(shifts.begin(),shifts.end(),0LL);
        string ans = "";
        for(int i = 0;i<s.size();i++){
            ans+=(((s[i]-'a')+cnt)%26+'a');
            cnt-=shifts[i];
        }
        return ans;
    }
};