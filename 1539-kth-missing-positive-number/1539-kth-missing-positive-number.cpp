class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> v(*max_element(arr.begin(),arr.end())+1,false);
        for(auto &it:arr){
            v[it-1] = true;
        }
        int i = 0;
        int cnt = 0;
        while(cnt<k){
            while(i<v.size() and v[i]!=false){
                i++;
            }
            i++;
            if(i>=v.size()){
                break;
            }
            cnt++;
        }
        if(i<v.size()){
            return i;
        }
        i--;
        while(cnt<k){
            i++;
            cnt++;
        }
        return i;
    }
};