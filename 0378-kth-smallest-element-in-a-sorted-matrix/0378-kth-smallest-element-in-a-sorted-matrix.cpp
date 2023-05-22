class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> p;
        int i = 0;
        int j = 0;
        int a = 0;
        while(i<n){
            j = 0;
            while(j<n){
                if(a == k) break;
                p.push(matrix[i][j]);
                j++;
                a++;
            }
            if(a == k) break;
            i++;
        }

        while(i<n){
            while(j<n){
                if(p.top()>matrix[i][j]){
                    p.pop();
                    p.push(matrix[i][j]);
                }
                j++;
            }
            j= 0;
            i++;
        }
        return p.top();
    }
};