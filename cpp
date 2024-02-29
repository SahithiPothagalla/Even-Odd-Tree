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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;
        while (!q.empty()) {
            int prev = evenLevel ? INT_MIN : INT_MAX;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if ((evenLevel && (node->val % 2 == 0 || node->val <= prev)) ||
                    (!evenLevel && (node->val % 2 != 0 || node->val >= prev))) {
                    return false;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                prev = node->val;
            }
            evenLevel = !evenLevel;
        }
        return true;
    }
};
