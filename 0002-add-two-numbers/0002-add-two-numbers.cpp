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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    ListNode *num1 = l1;
    ListNode *num2 = l2;
    ListNode *ans = new ListNode(0);
    ListNode *temp = ans;
    int carry = 0;
    while (num1 || num2) {
      int sum = 0;
      if (num1 != NULL) {
        sum += num1->val;
        num1 = num1->next;
      }
      if (num2 != NULL) {
        sum += num2->val;
        num2 = num2->next;
      }
      sum += carry;
      carry = 0;

      if (sum > 9) {
        sum = sum % 10;
        carry = 1;
      }

      ListNode *t = new ListNode(sum);
      temp->next = t;
      temp = temp->next;
    }

    if (carry) {
      ListNode *t = new ListNode(carry);
      temp->next = t;
    }
    return ans->next;
  }
};