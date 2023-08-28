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
    ListNode* deleteDuplicates(ListNode* head) {
       if(head == NULL) return NULL;
        
        
       int val = head->val; 
       ListNode* temp = head;
       ListNode* ans = new ListNode(head->val);
       ListNode* ans1 = ans;
        
       while(temp!=NULL){
           if(temp->val == val) {
                temp = temp->next;
               continue;
           }
           val = temp->val;
           ans->next = new ListNode(val);
           ans = ans->next;
           temp = temp->next;
       }
        
        return ans1;
    }
};