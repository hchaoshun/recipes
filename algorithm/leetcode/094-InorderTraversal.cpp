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
        stack<TreeNode*> S;
        vector<int> result;
        while (true) {
            goAlongLeftBranch(root, S);
            if (S.empty()) break;
            root = S.top();
            S.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
private:
    static void goAlongLeftBranch(TreeNode *root, stack<TreeNode*> &S) {
        while (root) {
            S.push(root);
            root = root->left;
        }
    }
};
