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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* evenStart = head->next;

        ListNode* even = evenStart;
        ListNode* odd = head;

        while (odd and odd->next or even and even->next) {
            if (odd and odd->next) {
                odd->next = odd->next->next;
                odd = odd->next;
            }
            if (even and even->next) {
                even->next = even->next->next;
                even = even->next;
            }
        }

        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = evenStart;

        return head;
    }
};