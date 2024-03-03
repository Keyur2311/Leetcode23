class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int k) {
    if (head == NULL)
      return NULL;
    if (head->next == NULL)
      return NULL;
    ListNode *p1 = head;
    ListNode *p2 = head;
    for (int i = 0; i < k; i++)
      p2 = p2->next;

    if (p2 == NULL)
      return head->next;
      
    while (p2->next != NULL) {
      p1 = p1->next;
      p2 = p2->next;
    }
    p1->next = p1->next->next;

    return head;
  }
};
