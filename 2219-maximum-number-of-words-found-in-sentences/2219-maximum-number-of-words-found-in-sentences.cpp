class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int ans = 0;
        int cnt = 0;
        for(auto &it:s){
            cnt = 0;
            for(int i = 0;i<it.size();i++){
                if(it[i]==' ') cnt++;
            }
            cnt++;
            ans = max(ans,cnt);
        }
        return ans;
    }
};