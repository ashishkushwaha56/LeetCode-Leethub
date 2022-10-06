class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        string s1;
        for(int c = s[0]-'A';c<=s[3]-'A';c++){
            for(int h = s[1]-'0';h<=s[4]-'0';h++){
                s1 = "";
                s1+=(c+'A');
                s1+=(h+'0');
                ans.push_back(s1);
            }
        }
        return ans;
    }
};