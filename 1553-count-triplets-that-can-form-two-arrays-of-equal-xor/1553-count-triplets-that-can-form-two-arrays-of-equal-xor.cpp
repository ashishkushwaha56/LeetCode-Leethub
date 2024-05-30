class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,vector<int>> mb = {{0,{-1}}};
        int ans= 0;
        int cnt = 0;
        for(int i = 0;i<arr.size();i++){
            cnt = cnt^arr[i];
            if(mb.find(cnt)!=mb.end()){
                auto it = mb.find(cnt);
                for(auto &x:(*(it)).second){
                    if(i-x>=2){
                        if(x==-1){
                            ans+=(i-x-1);
                        }
                        else{
                            ans+=(i-x-1);
                        }
                    }
                }
            }
            mb[cnt].push_back(i);
        }
        return ans;
    }
};