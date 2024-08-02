//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void call(vector<int>adj[],int n,int parent,int timer[],int optimal[],unordered_set<int> &res,int &time,bool visit[]) {
        timer[n]=optimal[n]=time++;
        int count=0;
        visit[n]=1;
        for (int i:adj[n]) {
            if (i==parent) continue;
            if (!visit[i]) {
                count++;
                call(adj,i,n,timer,optimal,res,time,visit);
                optimal[n]=min(optimal[n],optimal[i]);
                if (optimal[i]>=timer[n] && parent!=-1) res.insert(n);
            }
            else optimal[n]=min(optimal[n],timer[i]);
        }
        if (parent==-1 && count>1) res.insert(n);
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        int timer[n],optimal[n];
        bool visit[n];
        for (int i=0;i<n;i++) visit[i]=0;
        vector<int> res;
        unordered_set<int> res1;
        int time=0;
        call(adj,0,-1,timer,optimal,res1,time,visit);
        for (int i:res1) res.push_back(i);
        sort(res.begin(),res.end());
        if (res.size()==0) return {-1};
        return res;
    }
};



//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends