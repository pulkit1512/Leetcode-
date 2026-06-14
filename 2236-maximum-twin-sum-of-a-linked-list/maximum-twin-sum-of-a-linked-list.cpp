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
    int pairSum(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        curr=head;
        for(int i=0;i<count/2;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        ListNode*prev2=NULL;
        while(curr){
           ListNode*temp=curr->next;
           curr->next=prev2;
           prev2=curr;
           curr=temp;
        }
        int ans=0;
        while(head){
            ans=max(ans,head->val+prev2->val);
            head=head->next;
            prev2=prev2->next;
        }
        return ans;
    }
};