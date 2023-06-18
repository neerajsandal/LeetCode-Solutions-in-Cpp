//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
Node *f(int postorder[], int postStart, int postEnd, int inorder[], int inStart, int inEnd, map<int, int> &map)
{
    if(postEnd < postStart || inEnd < inStart) return NULL;
    Node *root = new Node(postorder[postEnd]);

    int index = map[root->data];
    int nums = index-inStart;

    root->left = f(postorder, postStart, postStart+nums-1, inorder, inStart, index-1,map);
    root->right = f(postorder, postStart+nums, postEnd-1,inorder, index+1, inEnd, map);
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int inorder[], int postorder[], int n) {
    map<int, int> map;
    for(int i = 0; i < n; i++)
        map[inorder[i]] = i;
        
    Node *root = f(postorder, 0, n-1, inorder, 0, n-1, map);
    return root;
}
