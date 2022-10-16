class MapSum {
public:
    int i,j;
    unordered_map<string,int> mb;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mb[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto &it:mb){
            i = 0,j=0;
            for(;i<it.first.size() and j<prefix.size();i++,j++){
                if(it.first[i]!=prefix[j]) break;
            } 
            if(j==prefix.size()) ans+=it.second;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */