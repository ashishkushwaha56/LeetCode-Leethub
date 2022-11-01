class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i = matrix.size()-1;
        int j;
        int temp;
        int prev;
        // bool ok = true;
        while(i>=0){
            j = 0;
            temp = i;
            prev = matrix[i][j];
            while(i<=matrix.size()-1 and j<=matrix[0].size()-1){
                if(matrix[i][j]!=prev){
                    return false;
                }
                i++;
                j++;
            }
            i = temp;
            i--;
        }
        j = 0;
        while(j<=matrix[0].size()-1){
            i = 0;
            temp = j;
            prev = matrix[i][j];
            while(i<=matrix.size()-1 and j<=matrix[0].size()-1){
                if(matrix[i][j]!=prev){
                    return false;
                }
                i++;
                j++;
            }
            j = temp;
            j++;
        }
        return true;
    }
};