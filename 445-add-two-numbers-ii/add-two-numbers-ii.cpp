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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        
        while(l1!=nullptr){
            s1.push(l1->val);
            l1=l1->next;
        }

        while(l2!=nullptr){
            s2.push(l2->val);
            l2=l2->next;
        }

        ListNode*ans = nullptr;
        int carry =0;
        while(!s1.empty() || !s2.empty() ||carry!=0){
            int d1 = !s1.empty()?s1.top():0;
            int d2 = !s2.empty()?s2.top():0;
            int sum =d1+d2+carry;
            carry = sum/10;
            sum=sum%10;
        

        ListNode*node = new ListNode(sum);
        node->next=ans;
        ans=node;
        if(!s1.empty()) s1.pop();
        if(!s2.empty()) s2.pop();
        }
        return ans;
    }
};