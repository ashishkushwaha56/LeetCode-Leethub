class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<long long> pre(nums.size()+1);
        for(int i = 1;i<nums.size()+1;i++){
            pre[i] = pre[i-1]+nums[i-1];
        }
        // for(auto &it:pre){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        vector<long long> ans;
        long long a;
        long long b;
        long long net;
        for(int i = 0;i<queries.size();i++){
            auto it = lower_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
            a = 0;
            b = 0;
            if(it == nums.size()) {
                a = abs(pre[it]-(it)*queries[i]);
            }
            else if(it == 0){
                b = ((pre[pre.size()-1]-pre[it])-((pre.size()-it-1)*queries[i]));
            }
            else{
                if(nums[it]>queries[i]){
                    it--;
                }
                a = abs(pre[it+1]-(it+1)*queries[i]);
                b = ((pre[pre.size()-1]-pre[it+1])-((pre.size()-it-2)*queries[i]));
            }

            // cout<<it<<endl;
            // a = abs(pre[it+1]-(it+1)*queries[i]);
            // cout<<"a => " <<a<<endl;
            // if(nums[it]>queries[i]){
            //     b = ((pre[pre.size()-1]-pre[it])-((pre.size()-it-1)*queries[i]));
            // }
            // else b = ((pre[pre.size()-1]-pre[it+1])-((pre.size()-it-2)*queries[i]));
            // cout<<"b => "<<b<<endl;
            if(b<0) b = -b;
            ans.push_back(a+b);
        }
        return ans;
    }
};