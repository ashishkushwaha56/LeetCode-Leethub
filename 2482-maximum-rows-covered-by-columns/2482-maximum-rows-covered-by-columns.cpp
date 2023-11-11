class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v;
        vector<int> temp;

        vector<int> count_one(m);
        for(int i = 0;i<m;i++){
            count_one[i] = count(matrix[i].begin(),matrix[i].end(),1);
        }
        function<void(int)> dfs = [&](int i)->void{
            if(i>=n) {
                if(temp.size() == numSelect){
                    v.push_back(temp);
                }
                return;
            }
            temp.push_back(i);
            dfs(i+1);
            temp.pop_back();
            dfs(i+1);
        };
        dfs(0);
        int ans = 0;
        int cnt = 0,one = 0;
        for(auto &it:v){
            cnt = 0;
            
            for(int i = 0;i<m;i++){
                one = 0;
                for(int j = 0;j<it.size();j++){
                    one+=(matrix[i][it[j]] == 1);
                }
                if(count_one[i] == one) cnt++;
            }
            ans= max(ans,cnt);

        }
        return ans;
    }
};