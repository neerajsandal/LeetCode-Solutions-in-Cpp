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
    bool isLeaf(Node *root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        else return false;
    }
    void left_traverse(Node *root, vector<int> &ans)
    {
        while(root!=NULL && !isLeaf(root)){
            ans.push_back(root->data);
            if(root->left) root = root->left;
            else root = root->right;
        }
    }
    
    void leafNodes(Node *root, vector<int> &ans)
    {
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left != NULL) leafNodes(root->left, ans);
        if(root->right != NULL)leafNodes(root->right, ans);
    }
    
     void right_traverse_reverse(Node *root, vector<int> &ans)
    {
        vector<int> temp;
        while(root != NULL && !isLeaf(root)){
            temp.push_back(root->data);
            if(root->right) root = root->right;
            else root = root->left;
        }
        
        for(int i = temp.size()-1; i >= 0; i--)
        {
            ans.push_back(temp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
            return ans;
        }
        // root
        ans.push_back(root->data);
        // left
        left_traverse(root->left, ans);
        // leaves
        leafNodes(root, ans);
        //right
        right_traverse_reverse(root->right, ans);
        return ans;
    }
    //4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8
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