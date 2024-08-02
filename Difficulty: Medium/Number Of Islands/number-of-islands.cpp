//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int find(vector<vector<int>>& a,int val,int m) {
        if (a[val/m][val%m]==val) return val;
        return a[val/m][val%m]=find(a,a[val/m][val%m],m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        vector<vector<int>> parent(n,vector<int>(m));
        int c=0;
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) parent[i][j]=c++;
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        vector<int> res;
        c=0;
        for (auto i:op) {
            int row=i[0],col=i[1];
            if (visited[row][col]) {
                res.push_back(res.back());
                continue;
            }
            visited[row][col]=1;
            c++;
            if (row>0 && visited[row-1][col]) {
                int left=find(parent,parent[row][col],m),right=find(parent,parent[row-1][col],m);
                c-=(left!=right);
                parent[left/m][left%m]=right;
            }
            if (col>0 && visited[row][col-1]) {
                int left=find(parent,parent[row][col],m),right=find(parent,parent[row][col-1],m);
                c-=(left!=right);
                parent[left/m][left%m]=right;
            }
            if (row<n-1 && visited[row+1][col]) {
                int left=find(parent,parent[row][col],m),right=find(parent,parent[row+1][col],m);
                c-=(left!=right);
                parent[left/m][left%m]=right;
            }
            if (col<m-1 && visited[row][col+1]) {
                int left=find(parent,parent[row][col],m),right=find(parent,parent[row][col+1],m);
                c-=(left!=right);
                parent[left/m][left%m]=right;
            }
            res.push_back(c);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends