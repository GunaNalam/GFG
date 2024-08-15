//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int call(int arr[],int start,int end) {
        if (start==end) return 0;
        int count=1e9;
        for (int k=start;k<end;k++) 
            count=min(count,arr[start-1]*arr[k]*arr[end]+call(arr,start,k)+call(arr,k+1,end));
        return count;
    }
    int matrixMultiplication(int n, int arr[]) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=n-1;i>0;i--) {
            for (int j=i+1;j<n;j++) {
                int start=i,end=j,count=1e9;
                // if (start==end) continue;
                for (int k=start;k<end;k++) 
                    count=min(count,arr[start-1]*arr[k]*arr[end]+dp[i][k]+dp[k+1][end]);
                dp[i][j]=count;
            }
        }
        // for (auto i:dp) {
        //     for (int j:i) cout<<j<<" ";
        //     cout<<"\n";
        // }
        return dp[1][n-1];
        // return call(arr,1,n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends