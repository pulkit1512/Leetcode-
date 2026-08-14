class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head1 = nullptr;
        ListNode* tail = nullptr;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                if (!head1) {
                    head1 = tail = list2;
                } else {
                    tail->next = list2;
                    tail = tail->next;
                }
                list2 = list2->next;
            } else {
                if (!head1) {
                    head1 = tail = list1;
                } else {
                    tail->next = list1;
                    tail = tail->next;
                }
                list1 = list1->next;
            }
        }

        // Attach remaining elements
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        return head1;
    }
};
