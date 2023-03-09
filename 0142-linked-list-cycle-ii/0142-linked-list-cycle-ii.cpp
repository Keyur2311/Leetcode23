/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
          if(head==NULL || head->next==NULL) return NULL;
          
           ListNode *slow = head;
           ListNode *fast = head;
           bool cycle = false;
           while(fast!=NULL && fast->next!=NULL) {
               fast=fast->next->next;
               slow=slow->next;
               
               if(slow==fast){
                   cycle = true;
                   break;
               }
           }
           
           if(!cycle) return NULL;
        
           ListNode* temp = head;
           while(fast!=temp){
               fast=fast->next;
               temp=temp->next;
           }
        
           return temp;
    }
};