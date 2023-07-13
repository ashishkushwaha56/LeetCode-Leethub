class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
       int l = -1;
       for(int i = arr.size()-1;i>=1;i--){
           if(arr[i-1]>arr[i]){
               l = i-1;
               break;
           }
       } 
       if(l==-1) return arr;
       int j =arr.size()-1;
    //    while(j>=0 and arr[j]==arr[l]){
    //        j--;
    //    }
       while((arr[j]>= arr[l] and (j>l)) or arr[j]==arr[j-1]) j--;
       swap(arr[l],arr[j]);
       return arr;
    }
};