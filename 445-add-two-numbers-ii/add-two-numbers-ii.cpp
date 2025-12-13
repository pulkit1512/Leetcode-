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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverseList(l1);
        ListNode* head2 = reverseList(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) {
                sum += head1->val;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->val;
                head2 = head2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return reverseList(dummy->next);
    }
};