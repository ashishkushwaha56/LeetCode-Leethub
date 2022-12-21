class Solution {
public:

    int root(vector<int>&arr,int a){
        while(arr[a]!=a){
            arr[a] = arr[arr[a]];
            a = arr[a];
        }
        return a;
    }
    bool find(vector<int> & arr,int a,int b){
        if(root(arr,a) == root(arr,b)){
            return true;
        }
        else{
            return false;
        }
    }

    void union_(vector<int> &arr,vector<int> &arr_size,int A,int B){
        int root_A = root(arr,A);
        int root_B = root(arr,B);
        if(arr_size[root_A]>arr_size[root_B]){
            arr[root_B] = arr[root_A];
            arr_size[root_B]+=arr_size[root_A];
        }
        else{
            arr[root_A] = arr[root_B];
            arr_size[root_A]+=arr_size[root_B];
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> arr(isConnected.size());
        vector<int> arr_size(isConnected.size(),1);
        for(int i = 0;i<arr.size();i++){
            arr[i]=i;
        }
        for(int i = 0;i<isConnected.size();i++){
            for(int j = 0;j<isConnected[i].size();j++){
                
                if(isConnected[i][j] == 1){
                    if(!find(arr,i,j))
                        union_(arr,arr_size,i,j);
                }
            }
        }   
        for(auto &it:arr){
            cout<<it<<" ";
        }
        cout<<endl;
        unordered_set<int> s; 
        for(int i = 0;i<arr.size();i++){

            s.insert(root(arr,arr[i]));
        }  
        return s.size();
    }
};