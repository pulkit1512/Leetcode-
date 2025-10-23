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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count<k) return head;
        ListNode*prev=NULL;
        ListNode*curr=head;
        int n=k;
        while(k){
            ListNode*temp2=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp2;
            k--;
        }
        head->next=reverseKGroup(curr,n);
        // 'prev' now points to the new head of the reversed k-group so we retunr the prev  

        return prev;
    }
};