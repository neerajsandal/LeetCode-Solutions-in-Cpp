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
class Solution {
    vector<int> v;
public:
    void sum(TreeNode* root, int temp){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            temp = temp*10+root->val;
            v.push_back(temp);
            return;
        }
        temp = temp*10+root->val;
        if(root->left){
            sum(root->left, temp);
        }
        if(root->right){
            sum(root->right, temp);
        }
    }
    int sumNumbers(TreeNode* root) {
        sum(root,0);
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            ans += v[i];
        }
        return ans;
    }
};