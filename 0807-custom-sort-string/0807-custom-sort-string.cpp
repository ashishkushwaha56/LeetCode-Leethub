class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26);
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        string ans = "";
        int j = 0;
        int i = 0;
        while(j<order.size()){
            if(v[order[j]-'a']>0){
                while(v[order[j]-'a']>0){
                    ans+=order[j];
                    v[order[j]-'a']--;
                }
                j++;
            }
            else{
                j++;
                // continue;
            }
        }
        for(int i =0;i<26;i++){
            while(v[i]>0){
                ans+=(i+'a');
                v[i]--;
            }
        }
        return ans;
    }
};