//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pp pair<int,pair<int,int>>
class Solution
{
	public:
	int find(int A[],int n) {
	    if (A[n]==n) return n;
	    return A[n]=find(A,A[n]);
	}
    int spanningTree(int n, vector<vector<int>> adj[]) {
        priority_queue<pp,vector<pp>,greater<pp>> a;
        for (int j=0;j<n;j++) for (auto i:adj[j]) {
            a.push({i[1],{j,i[0]}});
            // cout<<j<<" "<<i[0]<<" "<<i[1]<<"\n";
        }
        int c=0,A[n];
        for (int i=0;i<n;i++) A[i]=i;
        while (!a.empty()) {
            auto t=a.top();
            a.pop();
            int left=find(A,t.second.first);
            int right=find(A,t.second.second);
            if (left!=right) {
                A[left]=right;
                c+=t.first;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends