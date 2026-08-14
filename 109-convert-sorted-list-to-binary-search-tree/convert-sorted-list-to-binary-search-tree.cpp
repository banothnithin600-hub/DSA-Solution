/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   TreeNode*BST(vector<int>arr,int start,int end){
    if(start>end){
        return 0;
    }
    int mid = start+(end-start)/2;
     TreeNode*cur = new TreeNode(arr[mid]);
     cur->left = BST(arr,start,mid-1);
     cur->right = BST(arr,mid+1,end);
    return cur;
   }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        return BST(arr,0,arr.size()-1);
    }
};