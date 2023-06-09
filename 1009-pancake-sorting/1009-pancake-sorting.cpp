class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        map<int,int> mb;
        vector<int> ans;
        for(int i = 0;i<arr.size();i++){
            mb[arr[i]] = i+1;
        }
        int j = arr.size()-1;
        while(j>=0){
            if(arr[j]!=j+1){
                ans.push_back(mb[j+1]);
                reverse(arr.begin(),arr.begin()+mb[j+1]);
                for(int i = 0;i<mb[j+1];i++){
                    mb[arr[i]] = i+1;
                }
                ans.push_back(j+1);
                reverse(arr.begin(),arr.begin()+j+1);
                for(int i = 0;i<j+1;i++){
                    mb[arr[i]] = i+1;
                }
                mb[arr[j]] = j+1;
                j--;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};