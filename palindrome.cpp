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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) {
            return true;
        }

        int len = 0;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            len += 1;
        }

        int mid = (len % 2 == 0) ? len / 2 : (len / 2) + 1;

        ListNode* middle = head;
        for (int i = 0; i < mid; i += 1) {
            middle = middle->next;
        }

        middle = reverseList(middle);

        ListNode* l1 = head;
        ListNode* l2 = middle;

        bool palindrome = true;

        while (l1 and l2) {
            if (l1->val != l2->val) {
                palindrome = false;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return palindrome;
    }

    void printList(ListNode* head) {
        std::cout << "L: ";
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            std::cout << curr->val << " ";
        }
        std::cout << "\n";
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};