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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
    	if(root == NULL){
    	    return ans;
    	}
    	
    	queue<TreeNode*> q;
    	q.push(root);
    	
        vector<int> v;
        v.push_back(root->val);
    	ans.push_back(v);
    	
    	int i = 0; 
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> v; 
    	    for(int i = 0; i < size; i++){
                TreeNode *temp = q.front();
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                    v.push_back(temp->left->val);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                    v.push_back(temp->right->val);
                }
    	    }
    	    i++;
    	    if(i % 2 != 0){
    	        reverse(v.begin(), v.end());
    	    }
    	    if(v.size() != 0)
    	    ans.push_back(v);
    	}
    	return ans;
    }
};