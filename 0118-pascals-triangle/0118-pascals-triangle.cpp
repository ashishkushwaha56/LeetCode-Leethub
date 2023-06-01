class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 1
        // 1 1
        // 1 2 1
        // 1 3 3 1
        // 1 4 6 4 1
        vector<vector<int>> v;
        vector<int> temp = {1};
        v.push_back(temp);
        vector<int> ans;
        for(int i=1;i<numRows;i++){
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
        return v;

    }
};