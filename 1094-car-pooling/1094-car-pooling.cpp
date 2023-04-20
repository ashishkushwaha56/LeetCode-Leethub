class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001);
        for(auto &it:trips){
            v[it[1]]+=it[0];
            v[it[2]]-=it[0];
        }
        for(int i = 0;i<1001;i++){
            capacity-=v[i];
            if(capacity<0) return false;
        }
        return true;
	}
};