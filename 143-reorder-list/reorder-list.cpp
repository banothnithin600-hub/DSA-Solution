class Solution {
private:
    
    ListNode* splitAtMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (prev != nullptr) {
            prev->next = nullptr; 
        }
        return slow;
    }

   
    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode* righthead = splitAtMid(head);
        ListNode* rightHeadrev = rev(righthead);
        
        ListNode* left = head;
        ListNode* right = rightHeadrev;
        
        
        while (left != nullptr && right != nullptr) {
            ListNode* nextleft = left->next;
            ListNode* nextright = right->next;
            
           
            if (nextleft == nullptr) {
                left->next = right;
                break;
            }
            
            left->next = right;
            right->next = nextleft;
            
            left = nextleft;
            right = nextright;
        }
    }
};
