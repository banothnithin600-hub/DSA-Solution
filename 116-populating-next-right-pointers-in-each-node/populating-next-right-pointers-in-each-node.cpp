/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //vector<int>ans;
        if(root==nullptr){
            return nullptr;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            for(int i=0;i<level;i++){
            Node*cur = q.front();
            q.pop();
            //ans.push_back(cur->val);
             if (i < level - 1) {
                    cur->next = q.front();
                } else {
                    cur->next = nullptr; 
                }
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
           
            }
        }
         return root;
    }
};