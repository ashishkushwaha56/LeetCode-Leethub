class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum = accumulate(shifts.begin(),shifts.end(),0ll);
        for(int i = 0;i<s.size();i++){
            s[i]=((sum+(s[i]-'a'))%26+'a');
            sum-=shifts[i];
        }
        return s;
    }
};