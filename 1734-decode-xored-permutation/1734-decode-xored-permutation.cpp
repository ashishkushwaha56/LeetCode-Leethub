class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int> ans;
        int xor_total = 0;
        for(int i = 0;i<encoded.size()+1;i++){
            xor_total^=(i+1);
        }
        for(int i = 1;i<encoded.size();i+=2){
            xor_total^=encoded[i];
        }
        ans.push_back(xor_total);
        for(int i = 0;i<encoded.size();i++){
            ans.push_back(ans.back()^encoded[i]);
        }
        return ans;
    }
};