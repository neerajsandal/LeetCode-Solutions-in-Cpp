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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vect;
        if(root == NULL){
            return vect;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0){
            int size = q.size();
            vector<int> nanda;
            for(int i = 0; i < size; i++){ 
                TreeNode* temp = q.front();
                q.pop();
                nanda.push_back(temp->val);
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            vect.push_back(nanda);
        }
        reverse(vect.begin(), vect.end());
        return vect;
    }
};