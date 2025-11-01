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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> sets(nums.begin(),nums.end());
        ListNode* temp = head;
        ListNode* prev = NULL;
        // if the starting element are equal to the val
        while (head && sets.count(head->val)) {
            head = head->next;
        }
        while (temp) {
            if(sets.count(temp->val)){
                if(prev){
                    prev->next=temp->next;
                }
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head ;
    }
};