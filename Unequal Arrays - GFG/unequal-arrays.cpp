//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  	bool f(vector<int>&A,vector<int>&B){
  		int c1 = 0,c2 = 0;
  		int a1 = 0,a2 = 0;
  		long long  s1 = 0,s2 = 0;
  		for(int i = 0;i<A.size();i++){
  			s1+=A[i];
  			if(A[i]&1) c2++;
  			else  {
  				c1++;
  			}
  			s2+=B[i];
  			if(B[i]&1) a2++;
  			else a1++;
  		}
  		return (a1 == c1 and a2 == c2 and s1 == s2);
  	}
    long long solve(int N, vector<int> &A, vector<int> &B) {
        if(!f(A,B)) return -1;
        long long ans = 0;
        long long temp = 0;
        sort(A.begin(),A.end());
        // sort(B.begin(),B.end());

        unordered_map<int,int> mb;
        for(auto &it:B){
        	mb[it]++;
        }
        vector<int> oddA,evenA,newB;
        for(int i = 0;i<N;i++){
        	if(mb.find(A[i])!=mb.end()){
        		mb[A[i]]--;
        		if(mb[A[i]] == 0) mb.erase(A[i]);
        	}
        	else{
        		if(A[i]&1) oddA.push_back(A[i]);
        		else evenA.push_back(A[i]);
        	}
        }
        for(auto &it:mb){
        	while(it.second){
        		newB.push_back(it.first);
        		it.second--;
        	}
        }
        sort(newB.begin(),newB.end());
        int i = 0,j = 0,k = 0;
        while(i<newB.size()){
        	if(newB[i]&1){
        		if(j<oddA.size()){
        			temp+=abs(oddA[j]-newB[i]);
        			j++;
        		}
        		else return -1;
        	}
        	else {
        		if(k<evenA.size()){
        			temp+=abs(evenA[k]-newB[i]);
        			k++;
        		}
        		else return -1;
        	}
        	i++;
        }
        return temp/4;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends