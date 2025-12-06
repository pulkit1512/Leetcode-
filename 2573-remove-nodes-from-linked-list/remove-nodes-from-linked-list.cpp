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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        int maximum = INT_MIN;
        ListNode* head1 = nullptr;
        ListNode* tail = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            if (current->val >= maximum) {
                maximum = current->val;
                if (head1 == nullptr) {
                    head1 = current;
                    tail = current;
                } else {
                    tail->next = current;
                    tail = current;
                }
            }
            current = current->next;
        }

        if (tail != nullptr) tail->next = nullptr;
        return reverseList(head1);
    }
};
