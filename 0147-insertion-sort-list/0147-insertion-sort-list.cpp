class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummyHead(0);
        ListNode *node = head;
        while (node)
        {
            ListNode *prev = &dummyHead;
            ListNode *curr = dummyHead.next;
            while (curr && curr->val <= node->val)
            {
                prev = curr;
                curr = curr->next;
            }
            ListNode *next = node->next;
            prev->next = node;
            node->next = curr;
            node = next;
        }
        return dummyHead.next;
    }
};