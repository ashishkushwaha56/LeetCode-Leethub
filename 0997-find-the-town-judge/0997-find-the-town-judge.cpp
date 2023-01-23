class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> mb,nb;
        for(int i = 0;i<trust.size();i++){
            mb[trust[i][1]]++;
            nb[trust[i][0]]++;
        }
        for(auto &it:mb){
            if(it.second == n-1){
                if(nb.find(it.first)!=nb.end()){
                    return -1;
                }
                else{
                    return it.first;
                }
            }
        }
        if(n == 1) return 1;
        return -1;
    }
};