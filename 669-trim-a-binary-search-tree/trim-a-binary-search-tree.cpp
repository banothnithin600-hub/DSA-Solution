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
//    void inorder(TreeNode*root,vector<int>&ans){
//         if(root==nullptr){
//             return;
//         }
//         inorder(root->left,ans);
//         ans.push_back(root);
//         inorder(root->right,ans);
//    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // vector<int>ans;
        // inorder(root,ans);
        // vector<int>arr;
        // for(int i=0;i<ans.size();i++){
        //  if(ans[i]>=low && ans[i]<=mid){
        //     arr.push_back(ans[i]);
        //  }
        // }
     if(root==nullptr){
        return nullptr;
     }
     if(root->val>high){
        return trimBST(root->left,low,high);
     }
     if(root->val<low){
        return trimBST(root->right,low,high);
     }

    root->left= trimBST(root->left,low,high);
    root->right= trimBST(root->right,low,high);
     return root;
    }
};