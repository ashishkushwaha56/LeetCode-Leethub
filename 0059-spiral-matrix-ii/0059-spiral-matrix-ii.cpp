class Solution {
public:
    int count = 0;
    void check(vector<vector<int>> &v,int i,int j,int upper, int lower,int left,int right, int flag){
        if(flag == 0){
            if(i>lower){
                return;
            }
            else if(i == lower){
                right--;
                count++;
                v[i][j] = count;
                check(v,i,j-1,upper,lower,left,right,1);
            }
            else{
                count++;
                v[i][j] = count;
                check(v,i+1,j,upper,lower,left,right,0);
            }
        }
        else if(flag == 1){
            if(j<left){
                return;
            }
            else if(j == left){
                lower--;
                count++;
                v[i][j] = count;
                check(v,i-1,j,upper,lower,left,right,2);
            }
            else{
                count++;
                v[i][j] = count;
                check(v,i,j-1,upper,lower,left,right,1);
            }
        }
        else if(flag == 2){
            if(i<upper){
                return;
            }
            else if(i == upper){
                left++;
                count++;
                v[i][j] = count;
                check(v,i,j+1,upper,lower,left,right,3);
            }
            else{
                count++;
                v[i][j] = count;
                check(v,i-1,j,upper,lower,left,right,2);
            }
        }
        else if(flag == 3){
            if(j>right){
                return;
            }
            else if(j == right){
                upper++;
                count++;
                v[i][j] = count;
                check(v,i+1,j,upper,lower,left,right,0);
            }
            else{
                count++;
                v[i][j] = count;
                check(v,i,j+1,upper,lower,left,right,3);
            }
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        check(v,0,0,0,n-1,0,n-1,3);
        return v;
    }
};