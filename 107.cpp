class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int> > ans;
    if (root == NULL) return ans;
    q.push(root);
    while (!q.empty()) {
      int queue_size = q.size();
      vector<int> nodes;
      while (queue_size) {
        auto cur = q.front(); q.pop();
        if (cur) {
          q.push(cur->left); q.push(cur->right);
          nodes.push_back(cur->val);
        }
        queue_size--;
      }
      if (nodes.size()) ans.push_back(nodes);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};