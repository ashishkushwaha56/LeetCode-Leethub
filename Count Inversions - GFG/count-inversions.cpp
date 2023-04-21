//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long ans = 0;
    
    void merge(long long arr[],long long temp[],long long left,long long mid,long long right){
        long long i = left,j = mid,k = left;
        while(i<mid and j<=right){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
                
            }
            else {
                ans+=(mid-i);
                temp[k++] = arr[j++];
            }
        }
        while(i<mid) temp[k++] = arr[i++];
        while(j<=right) temp[k++] = arr[j++];
        for(int h = left;h<=right;h++){
            arr[h] = temp[h];
        }
    }
    void mergeSort(long long arr[],long long temp[],long long left, long long right){
        long long mid;
        if(left<right){
            mid = (left+right)/2;
            mergeSort(arr,temp,left,mid);
            mergeSort(arr,temp,mid+1,right);
            merge(arr,temp,left,mid+1,right);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        mergeSort(arr,temp,0,N-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends