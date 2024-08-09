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
  ListNode *findMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode *mergeList(ListNode *l1, ListNode *l2) {
    ListNode *x = new ListNode(0);
    ListNode *temp = x;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        temp->next = l1;
        l1 = l1->next;
      } else {
        temp->next = l2;
        l2 = l2->next;
      }
      temp = temp->next;
    }

    temp->next = l1 ? l1 : l2;
    ListNode *result = x->next;
    delete x;
    return result;
  }

  ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return head;

    ListNode *mid = findMid(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    ListNode *merged = mergeList(left, right);
    return merged;
  }
};
