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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode*temp = head;
        while(temp && count<k){
            temp=temp->next;
            count++;
        }
        
        if(count<k){
            return head;
        }
        temp=head;
        ListNode*prev = nullptr;
        ListNode*next = nullptr;
        count=0;
       while(temp && count<k){
        next = temp->next;
        temp->next=prev;
        prev = temp;
        temp=next;
        count++;
       }
       head->next=reverseKGroup(temp,k);
       return prev;
    }
};