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
  int getLength(ListNode *head) {
    int sz = 0;
    ListNode *tp = head;
    while (tp) {
      tp = tp->next;
      sz++;
    }
    return sz;
  }
  ListNode *deleteMiddle(ListNode *head) {
    if (head->next == NULL)
      return NULL;

    int len = getLength(head);

    ListNode *temp = head;
    for (int i = 0; i < len / 2 - 1; i++)
      temp = temp->next;

    temp->next = temp->next->next;
    return head;
  }
};