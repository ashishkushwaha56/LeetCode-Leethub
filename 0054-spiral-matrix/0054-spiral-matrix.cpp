class Solution {
public:
    vector<int> ans;
    void check(vector<vector<int>>&v,int i,int j,int upper,int lower,int left,int right,int flag){
        // cout<<i<<" "<<j<<" "<<flag<<endl;
        if(flag == 0){
            if(i>lower){
                return;
            }
            else if(i < lower){
                ans.push_back(v[i][j]);
                check(v,i+1,j,upper,lower,left,right,0);
            }
            else{
                 ans.push_back(v[i][j]);
                right--;
                check(v,i,j-1,upper,lower,left,right,1);
            }
        }
        else if(flag == 1){
            if(j<left) return;
            else if(j > left){
                ans.push_back(v[i][j]);
                check(v,i,j-1,upper,lower,left,right,1);
            }
            else{
                 ans.push_back(v[i][j]);
                lower--;
                check(v,i-1,j,upper,lower,left,right,2);
            }
        }
        else if(flag == 2){
            if(i<upper) return;
            else if(i>upper){
                ans.push_back(v[i][j]);
                check(v,i-1,j,upper,lower,left,right,2);
            }
            else{
                 ans.push_back(v[i][j]);
                left++;
                check(v,i,j+1,upper,lower,left,right,3);
            }
        }
        else if(flag == 3){
            if(j>right) return;
            else if(j<right){
                ans.push_back(v[i][j]);
                check(v,i,j+1,upper,lower,left,right,3);
            }
            else{
                 ans.push_back(v[i][j]);
                upper++;
                check(v,i+1,j,upper,lower,left,right,0);
            }
        }
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        check(matrix,0,0,0,matrix.size()-1,0,matrix[0].size()-1,3);
        return ans;
    }
};