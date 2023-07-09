class Solution {
public:
    int largestVariance(string s) {
        vector<int> v(26);
        for(auto &it:s){
            v[it-'a']++;
        } 
        int ans = 0;
        for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                int a = 0;
                int b = 0;
                if(j == i or v[i] ==0 or v[j] == 0)continue;
                for(int k = 0;k<2;k++){
                    a = 0;
                    b = 0;
                    for(auto &it:s){
                        if(it == i+'a') a++;
                        else if(it == j+'a') b++;
                        if(b>a) {
                            a = 0;
                            b = 0;
                        }
                        if(a>0 and b>0){
                            ans = max(ans,a-b);
                        }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};