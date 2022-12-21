class Solution {
public:
    
    bool find(vector<int>&arr,int a,int b){
        return (root(arr,a) == root(arr,b));
    }
    
    int root(vector<int>&arr,int a){
        while(arr[a]!=a){
            arr[a] = arr[arr[a]];
            a = arr[a];
        }
        return a;
    }
    
    void union_(vector<int> &arr,vector<int>&arr_size,int A,int B){
        int root_A = root(arr,A);
        int root_B = root(arr,B);
        if(arr_size[root_A]>arr_size[root_B]){
            arr[root_B] = arr[root_A];
            arr_size[root_A]+=arr_size[root_B];
        }
        else{
            arr[root_A] = arr[root_B];
            arr_size[root_B]+=arr_size[root_A];
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> arr(edges.size());
        for(int i = 0;i<arr.size();i++){
            arr[i] = i;
        }
        vector<int> arr_size(edges.size(),1);
        for(int i = 0;i<edges.size();i++){
            if(find(arr,edges[i][0]-1,edges[i][1]-1)){
                return {edges[i][0],edges[i][1]};
            }
            else{
                union_(arr,arr_size,edges[i][0]-1,edges[i][1]-1);
            }
        }
        return {};
    }
};