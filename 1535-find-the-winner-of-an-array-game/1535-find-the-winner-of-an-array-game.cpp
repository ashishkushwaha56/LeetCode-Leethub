class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        vector<int> next_greater(arr.size());
        stack<pair<int,int>> s;
        for(int i = arr.size()-1;i>=0;i--){
            if(s.empty()){
                next_greater[i] = -1;
                s.push({arr[i],i});
            }
            else{
                while(!s.empty() and s.top().first<arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    next_greater[i] = -1;
                }
                else{
                    next_greater[i] = s.top().second;
                }
                s.push({arr[i],i});
            }
        }
        int maxe = *max_element(arr.begin(),arr.end());
        vector<int> left_max(arr.size());
        left_max[0] = arr[0];
        for(int i = 1;i<arr.size();i++){
            left_max[i] = max(left_max[i-1],arr[i]);
        }
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == maxe) return arr[i];
            if(i == 0){
                if(abs(next_greater[i]-i)-1>=k) return arr[i];
                continue;
            }
            if(left_max[i-1]>arr[i]) continue;
            if(abs(next_greater[i]-i)>=k) return arr[i];
        }
        return 0;
    }
};