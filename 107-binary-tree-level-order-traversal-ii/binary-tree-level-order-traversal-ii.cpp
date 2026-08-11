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
void traverse(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return; // Base case like your root == nullptr

        // If this is the first time we reached this depth, add a new level
        if (res.size() == level) {
            res.push_back({});
        }

        // Add current value to its corresponding level
        res[level].push_back(root->val);

        // Move to the next level recursively (your code's style)
        traverse(root->left, level + 1, res);
        traverse(root->right, level + 1, res);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     vector<vector<int>> res;
        traverse(root, 0, res);
        reverse(res.begin(),res.end());
        return res;
    }
};