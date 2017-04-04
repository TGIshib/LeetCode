/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return ans(root);
    }
    
    int ans(TreeNode* root, bool isRight = false){
        if(root == NULL) return 0;
        if(isLeave(root) && isRight) return root->val;
        return ans(root->left, true) + ans(root->right);
    }
    
    bool isLeave(TreeNode * r){
      if(r == NULL) return false;
      return r->right == NULL && r->left == NULL;  
    } 
};