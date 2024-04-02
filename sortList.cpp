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
    ListNode* mergeSort(ListNode* left, ListNode* right) {
        ListNode dummy{};
        ListNode* curr = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        if (left) {
            curr->next = left;
        } else if (right) {
            curr->next = right;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr or head->next == nullptr) {
            return head;
        }

        ListNode* mid = split_and_getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergeSort(left, right);
    }

    ListNode* split_and_getMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* midPrev = nullptr;

        while (fast and fast->next) {
            midPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        midPrev->next = nullptr;

        return slow;
    }
};