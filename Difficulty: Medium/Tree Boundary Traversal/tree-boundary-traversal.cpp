//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        vector<Node*> left;
        Node* temp=root;
        left.push_back(temp);
        temp=temp->left;
        while (temp) {
            left.push_back(temp);
            if (temp->left) temp=temp->left;
            else temp=temp->right;
        }
        stack<Node*> a;
        a.push(root);
        while (!a.empty()) {
            temp=a.top();
            a.pop();
            if (temp->right) a.push(temp->right);
            if (temp->left) a.push(temp->left);
            if (!temp->right && !temp->left) {
                if (temp==left.back()) continue;
                left.push_back(temp);
            }
        }
        temp=root->right;
        while (temp) {
            a.push(temp);
            // cout<<"B: "<<a.top()->data<<"\n";
            if (temp->right) temp=temp->right;
            else temp=temp->left;
        }
        if (!a.empty() && a.top()==left.back()) left.pop_back();
        while (!a.empty()) {
            left.push_back(a.top());
            a.pop();
        }
        // for (auto i:left) cout<<i->data<<" ";
        vector<int> res;
        for (auto i:left) res.push_back(i->data);
        return res;
    }
};



//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends