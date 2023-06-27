class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i =0;i<k and i<nums1.size();i++){
        	pq.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>> ans;
        pair<int,pair<int,int>> temp;
        while(!pq.empty() and ans.size()<k){
        	temp = pq.top();
        	pq.pop();
        	ans.push_back({nums1[temp.second.first],nums2[temp.second.second]});
        	if(temp.second.second+1<nums2.size()){
        		pq.push({nums1[temp.second.first]+nums2[temp.second.second+1],{temp.second.first,temp.second.second+1}});
        	}
        }
        return ans;
    }
};