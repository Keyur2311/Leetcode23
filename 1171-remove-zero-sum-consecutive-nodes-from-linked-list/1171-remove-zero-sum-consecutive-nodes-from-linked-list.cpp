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
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode *dm = new ListNode(0);
    dm->next = head;

    ListNode *curr = dm;

    while (curr) {
      ListNode *temp = curr->next;
      int sum = 0;
      while (temp) {
        sum += temp->val;
        if (sum == 0){
          curr->next = temp->next;
          // break;
        }
        temp = temp->next;
      }
      curr = curr->next;
    }
    return dm->next;
  }
};