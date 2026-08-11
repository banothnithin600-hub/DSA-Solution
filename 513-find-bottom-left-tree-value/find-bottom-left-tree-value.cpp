class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;  // Handle case for an empty tree

        queue<TreeNode*> q;   // Queue for BFS
        q.push(root);
        TreeNode* currentNode = nullptr;  // To store the last visited node

        while (!q.empty()) {
            currentNode = q.front();
            q.pop();

            // Push left first to ensure leftmost node is processed first
           if (currentNode->right) {
                q.push(currentNode->right);
            }
            if (currentNode->left) {
                q.push(currentNode->left);
            }
            
        }
        
        return currentNode->val;  // Return the last node visited (bottom left value)
    }
};