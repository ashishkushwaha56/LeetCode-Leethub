class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        vector<int> temp = {1};
        v.push_back(temp);
        vector<int> ans;
        for(int i=1;i<rowIndex+1;i++){
            for(int j = 0;j<=i;j++){
                if(j == 0 or j == i){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(temp[j]+temp[j-1]);
                }
            }
            temp = ans;
            ans.clear();
            v.push_back(temp);
        }
        return v[rowIndex];
    }
};