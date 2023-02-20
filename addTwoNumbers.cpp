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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* current = new ListNode();
    ListNode* result = current;

    int carry {};

    while (l1 or l2 or carry) {
        int sum {};
        
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = (sum >= 10) ? 1 : 0;
        
        current->val = sum % 10; 
        current->next = (l1 or l2 or carry) ? new ListNode() : nullptr;
        current = current->next;
    }

    return result;
}
