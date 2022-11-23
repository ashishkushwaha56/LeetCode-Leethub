class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mb;
        for(int i = 0;i<tasks.size();i++){
            mb[tasks[i]]++;
        }
        int ans = 0;
        // for(auto &it:mb){
        //     cout<<it.second<<endl;
        // }
        for(auto &it:mb){
            if(it.second<2) return -1;
            else if(it.second%3 == 1){
                ans+=2;
                ans+=(it.second-4)/3;
            }
            else if(it.second%3 == 0){
                ans+=it.second/3;
            }
            else{
                ans+=1;
                ans+=it.second/3;
            }
        }
        return ans;
    }
};