class Solution {
public:
    vector<vector<int>> v;
    int m_,n_;
    int i = 0,j = 0;
    Solution(int m, int n) {
        v.resize(m,vector<int>(n));
        m_ = m,n_ = n;
        srand(time(0));
    }
    
    vector<int> flip() {
        v[i][j] = 1;
        // v[a][b] = 1;
        int a = i;
        int b = j;
        if(i == m_-1 and j == n_-1){
            i = 0,j = 0;
        }
        else if(i == m_-1){
            j++;
            i = 0;
        }
        else{
            i++;
        }
        return {a,b};
    }
    
    void reset() {
        v.resize(m_,vector<int>(n_));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */