class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        map<int,int> index1,index2,value1,value2;
        for(int i = 0;i<values.size();i++){
            index1[i] = values[i]+i;
            index2[i] = values[i]-i;
            value1[values[i]+i]++;
            value2[values[i]-i]++;
        }
        int ans = 0;
        int a ,b;
        int index, value;
        // for(auto &it:value2){
        //     cout<<it.first<<" "<<endl;
        // }
        for(auto &it:index1){
            index = (it).first;
            value = index2[index];
            // index2.erase(index);
            value2[value]--;
            if(value2[value] == 0){
                value2.erase(value);
            }
            auto i = value2.end();
            if(value2.size()==0){
                continue;
            }
            i--;
            // if(i!=value2.)
            ans = max(ans,(it).second+(*i).first);
            // value2[value]++;
        }
        return ans;
    }
};