/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
class Solution {
    vector<int> v,v1;
    
public:
    void helper(TreeNode *root){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
        }
        helper(root->left);
        helper(root->right);
    }
    void helper1(TreeNode *root){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            v1.push_back(root->val);
        }
        helper1(root->left);
        helper1(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL && root2 != NULL){
            return false;
        }
        if(root1 != NULL && root2 == NULL){
            return false;
        }
        helper(root1);
        helper1(root2);
        
        if(v.size() != v1.size()){
            return false;
        }
        
        for(int i = 0; i < v.size(); i++){
            if(v[i] != v1[i])
                return false;
        }
        return true;
    }
};