class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q) return root;
    vector<TreeNode*> ansp, ansq;
    find_n(root, p, ansp);
    find_n(root, q, ansq);
    for (int i = 1; i < min(ansp.size(), ansq.size()); i++) {
      if (ansp[i] != ansq[i]) return ansp[i - 1];
    }
    return ansp.size() < ansq.size() ? p : q;
  }

  bool find_n(TreeNode* root, TreeNode* p, vector<TreeNode*> &v) {
    if (root == NULL) return false;
    v.push_back(root);
    if (root == p) return true;
    if (find_n(root->left, p, v)) return true;
    if (find_n(root->right, p, v)) return true;
    v.pop_back();
    return false;
  }
};