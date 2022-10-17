class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mb;
        for(int i = 0;i<arr.size();i++){
            mb[((arr[i]%k)+k)%k]++;
        }
        for(auto &it:mb){
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(auto &it:mb){
            if(it.first == 0) {if(it.second&1) return false;}
            else if(mb.find(k-it.first)==mb.end()) return false;
            else if(mb[k-it.first]!=it.second) return false;
        }
        return true;
    }
};