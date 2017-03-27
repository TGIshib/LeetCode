class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
        
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        TreeNode* ret = root;
        if(root->val >= p->val && root->val >= q->val) ret = lca(root->left, p, q);
        else if(root->val <= p->val && root->val <= q->val) ret = lca(root->right, p, q);
        return ret == NULL ? root : ret;
    }
};