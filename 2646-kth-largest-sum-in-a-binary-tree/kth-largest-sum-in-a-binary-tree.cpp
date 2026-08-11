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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans;
        int maxl = INT_MIN;
      
        if(root==NULL){
          return -1;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            long long int sum =0;
            for(int i=0;i<level;i++){
                TreeNode*cur = q.front();
                q.pop();
                
                sum+=(long long)cur->val;

                if(cur->left){
                    q.push(cur->left);
                }

                if(cur->right){
                    q.push(cur->right);
                }
            }
            ans.push_back(sum);
        }
         
       // sort(ans.rbegin(),ans.rend());
       sort(ans.begin(),ans.end(),greater<long long>());
         long long n = ans.size();
       if(k>n || k<=0){ //suppose any greater value
        return -1;
       }

        return ans[k-1];
    }
};