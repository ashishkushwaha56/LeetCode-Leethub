class Solution {
public:
    pair<int,int> f(string s,int i,int j){
        while(i>=0 and j<s.size() and s[i] == s[j]){
            i--;j++;
        }
        return {i+1,j-1};
    }
    string longestPalindrome(string s) {
        pair<int,int> p1,p2;
        int maxlen = 0;
        string ans;
        for(int i = 0;i<s.size();i++){
            p1 = f(s,i,i);
            p2 = f(s,i,i+1);
            if(p1.second-p1.first+1>0){
                if(p1.second-p1.first+1>maxlen){
                    maxlen = p1.second-p1.first+1;
                    // cout<<
                    ans = s.substr(p1.first,p1.second-p1.first+1); 
                }
            }
            if(p2.second-p2.first+1>0){
                if(p2.second-p2.first+1>maxlen){
                    maxlen = p2.second-p2.first+1;
                    // cout<<
                    ans = s.substr(p2.first,p2.second-p2.first+1); 
                }
            }
        }
        return ans;
    }
};