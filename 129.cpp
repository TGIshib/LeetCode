class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
    
    int sum(TreeNode* node, int num){
        if(!node) return num;
        num *= 10;
        num += node->val;
        int res = 0;
        if(!node->left && !node->right) return num;
        if(node->left) res += sum(node->left, num); 
        if(node->right) res += sum(node->right, num);
        return  res;
    }
};