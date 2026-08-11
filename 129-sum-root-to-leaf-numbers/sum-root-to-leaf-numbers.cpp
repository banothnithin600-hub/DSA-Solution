/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root, vector<int>& sum, int csum) {
        if (root->left == nullptr && root->right == nullptr) {
            sum.push_back(csum);
            return;
        }
        if (root->left) {
            csum = csum * 10 + root->left->val;
            help(root->left, sum, csum);
            csum /= 10;
        }
        if (root->right) {
            csum = csum * 10 + root->right->val;
            help(root->right, sum, csum);
            csum /= 10;
        }
    }
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        vector<int> sum;
        help(root, sum, root->val);
        int ans = 0;
        for (auto it : sum) {
            ans += it;
        }
        return ans;
    }
};