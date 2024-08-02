//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(stack<int> &order,vector<bool>& visit,vector<vector<int>>& adj,int n) {
	    visit[n]=1;
	    for (int i:adj[n]) if (!visit[i]) dfs(order,visit,adj,i);
	    order.push(n);
	}
	int kosaraju(int n, vector<vector<int>>& adj) {
        int src=0,res=0;
        vector<bool> visit(n,0);
        stack<int> order;
        // q.push(0);
        // vector<vector<int>> res1;
        for (int i=0;i<n;i++) if (!visit[i]) dfs(order,visit,adj,i);
        vector<int> adjrev[n];
        for (int i=0;i<n;i++) for (int j:adj[i]) adjrev[j].push_back(i); 
        for (int i=0;i<n;i++) visit[i]=0;
        while (!order.empty()) {
            int t=order.top();
            order.pop();
            if (visit[t]) continue;
            visit[t]=1;
            res++;
            queue<int> q;
            q.push(t);
            visit[t]=1;
            while (!q.empty()) {
                int f=q.front();
                q.pop();
                for (int i:adjrev[f]) if (!visit[i]) {
                    q.push(i);
                    visit[i]=1;
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends