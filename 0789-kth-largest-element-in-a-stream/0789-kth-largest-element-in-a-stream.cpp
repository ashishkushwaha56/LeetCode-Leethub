class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> p;
    int size;
    KthLargest(int k, vector<int>& nums) {
        if(nums.size()>0){
            int i = 0;
            for(;i<min((int)k,(int)nums.size());i++){
                p.push(nums[i]);
            }
            if(k<nums.size()){
                for(;i<nums.size();i++){
                    if(p.top()<nums[i]){
                        p.pop();
                        p.push(nums[i]);
                    }
                }
            }
        }
        size = k;
    }
    
    int add(int val) {
        if(p.empty()){
            p.push(val);
            // size++;
            return p.top();
        }
        else if(p.size()<size){
            p.push(val);
            // size++;
            return p.top();
        }
        else if(p.top()<val){
            p.pop();
            p.push(val);
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */