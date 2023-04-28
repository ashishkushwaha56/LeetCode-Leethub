class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp = arr;
        int count = (arr.begin(),arr.end(),0);
        // count = coun;
        int j = 0;
        int i = 0;
        while(j<temp.size()){
            if(arr[i] == 0){
                temp[j] = 0;
                if(j+1<temp.size())
                    temp[j+1] = 0;
                j+=2;
            }
            else{
                temp[j] = arr[i];
                j++;
            }
            i++;
        }
        arr = temp;
    }
};