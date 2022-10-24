class Solution {
public:
    
    int ans = 0;
    int j;
    bool ok1;
    void check(vector<string>&arr,vector<int> &v,string &s,int i,int &n){
        if(i>=n){
            ans = max(ans,(int)s.size());
            return;
        }
        j = 0;
        ok1 = true;
        while(j<arr[i].size()){
            if(v[arr[i][j]-'a']>=1){
                ok1 = false;
            }
            v[arr[i][j]-'a']++;
            s+=arr[i][j];
            j++;
        }
        if(ok1){
            check(arr,v,s,i+1,n);
        }
        j = 0;
        while(j<arr[i].size()){
            s.pop_back();
            v[arr[i][j]-'a']--;
            j++;
        }
        check(arr,v,s,i+1,n);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> v(26);
        string s = "";
        check(arr,v,s,0,n);
        return ans;
    }
};