class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        map<int,int> index;
        map<int,pair<int,set<int>>> element;
        for(int i = 0;i<nums.size();i++){
            element[nums[i]].first++;
            element[nums[i]].second.insert(i);
            index[i] = nums[i];
        }
        int id,curr,left_ele,right_ele,left_id,right_id;
        
        while(!element.empty()){
            auto it=element.begin();
            id = *((*it).second.second.begin());
            ans+=(*it).first;
            
            (*it).second.second.erase(id);
            (*it).second.first--;
            if(element[(*it).first].first == 0){
                element.erase((*it).first);
            } 
            index.erase(id);
            left_id = id-1;
            right_id = id+1;
            if(index.find(left_id)!=index.end()){
                left_ele = index[left_id];
                element[left_ele].first--;
                element[left_ele].second.erase(left_id);
                if(element[left_ele].first == 0){
                    element.erase(left_ele);
                }
                index.erase(left_id);
            }
            if(index.find(right_id)!=index.end()){
                right_ele = index[right_id];
                element[right_ele].first--;
                element[right_ele].second.erase(right_id);
                if(element[right_ele].first == 0){
                    element.erase(right_ele);
                }
                index.erase(right_id);
            }
        }
        return ans;
    }
};