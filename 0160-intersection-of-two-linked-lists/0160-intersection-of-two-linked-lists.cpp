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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = 0, len2 = 0;

    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while (temp1 != NULL) {
      len1++;
      temp1 = temp1->next;
    }
    while (temp2 != NULL) {
      len2++;
      temp2 = temp2->next;
    }

    int diff = abs(len1 - len2);
    int x = 0;

    temp1 = headA, temp2 = headB;
    if (len1 > len2) {
      while (x < diff) {
        temp1 = temp1->next;
        x++;
      }
    } else {
      while (x < diff) {
        temp2 = temp2->next;
        x++;
      }
    }

    while (temp1 != NULL && temp2 != NULL) {
      if (temp1 == temp2)
        return temp1;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    return NULL;
  }
};