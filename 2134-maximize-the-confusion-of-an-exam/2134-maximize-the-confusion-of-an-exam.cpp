class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        vector<int> v1,v2;
        for(int i = 0;i<key.size();i++){
            if(key[i] == 'T') v1.push_back(i);
            else v2.push_back(i);
        }
        int ans1= 0;
        int ans2 = 0;
        if(k>=v1.size()) return key.size();
        if(k>=v2.size()) return key.size();
        int l = 0;
        int r = 0;
        // cout<<v1.size()<<endl;
        // cout<<v2.size()<<endl;
        for(int i = 0;i<=v1.size()-k;i++){
            // cout<<k<<endl;
            if(i == 0){
                l = -1;
            }
            else {
                l = v1[i-1];
            }
            if(i+k==v1.size()){
                r = key.size();
            }
            else{
                r = v1[i+k];
            }
            ans1 = max(ans1,r-l-1);
        }
        for(int i = 0;i<=v2.size()-k;i++){
            if(i == 0){
                l = -1;
            }
            else {
                l = v2[i-1];
            }
            if(i+k==v2.size()){
                r = key.size();
            }
            else{
                r = v2[i+k];
            }
            ans2 = max(ans2,r-l-1);
        }
        return max(ans1,ans2);
    }
    
};