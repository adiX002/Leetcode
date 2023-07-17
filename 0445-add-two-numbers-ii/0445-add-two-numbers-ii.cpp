class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = nullptr;
        while(curr != nullptr){
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        
        ListNode* curr = dummy;
        
        while(l1 != nullptr || l2 != nullptr){
            int a = l1 == nullptr ? 0 : l1->val;
            int b = l2 == nullptr ? 0 : l2->val;
            
            curr->next = new ListNode((a + b + carry)%10);
            
            carry = (a + b + carry)/10;
            
            curr = curr->next;
            
            if(l1 != nullptr){
                l1 = l1->next;
            }
            
            if(l2 != nullptr){
                l2 = l2->next;
            }
        }
        
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        
        return reverse(dummy->next);
    }
};