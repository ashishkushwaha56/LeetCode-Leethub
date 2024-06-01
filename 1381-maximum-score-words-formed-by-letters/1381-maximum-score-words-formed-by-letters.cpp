class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26);
        for(auto &it:letters){
            count[it-'a']++;
        }
        
        vector<int> temp;
        int ans = 0;
        function<void(int)> dfs = [&](int i)->void{
            if(i>=words.size()){
                bool ok = true;
                int cnt = 0;
                vector<int> b = count;
                for(auto &it:temp){
                    if(!ok) break;
                    for(auto &ele:words[it]){
                        if(b[ele-'a'] == 0){
                            ok = false;
                            break;
                        }
                        b[ele-'a']--;
                        cnt+=score[ele-'a'];
                    }
                }
                if(ok){
                    ans=max(ans,cnt);
                }
                return;
            }
            temp.push_back(i);
            dfs(i+1);
            temp.pop_back();
            dfs(i+1);
        };
        dfs(0);
        return ans;
    }
};