//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int call(int capacity,int weight[],int value[],int n) {
        // if (!capacity) return 0; // asalu zero 
        if (!n) return (capacity/weight[n])*value[n];
        int maxi=call(capacity,weight,value,n-1); // no pick 
        if (capacity>=weight[n]) maxi=max(maxi,value[n]+call(capacity-weight[n],weight,value,n)); // pick
        return maxi;
    }
    int knapSack(int n, int capacity, int value[], int weight[])
    {
        vector<int> cur(capacity+1);
        for (int i=0;i<=capacity;i++) cur[i]=(i/weight[0])*value[0];
        // prev=cur;
        for (int i=1;i<n;i++) {
            for (int j=0;j<=capacity;j++) 
                if (j>=weight[i]) cur[j]=max(cur[j],value[i]+cur[j-weight[i]]); // pick
        }
        return cur[capacity];
        // return call(capacity,weight,value,n-1);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends