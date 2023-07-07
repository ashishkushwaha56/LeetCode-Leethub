class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mb;
        for(auto &it:arr){
            mb[it]++;
        }
        vector<string> v;
        for(auto &it:arr){
            if(mb[it]==1) v.push_back(it);
        }
        if(v.size()<k) return "";
        return v[k-1];

    }
};