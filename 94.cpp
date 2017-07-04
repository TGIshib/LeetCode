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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) return ans;
		stack<TreeNode*> st;
		stack<bool> tb;
		st.push(root); tb.push(true);
		while (!st.empty()) {
			auto cur = st.top();
			st.pop();
			auto cur2 = tb.top();
			tb.pop();
			if (cur == NULL) continue;
			if (cur2 == false) {
				ans.push_back(cur->val);
				continue;
			}
			st.push(cur->right);
			tb.push(true);
			st.push(cur);
			tb.push(false);
			st.push(cur->left);
			tb.push(true);
		}
		return ans;
	}
};