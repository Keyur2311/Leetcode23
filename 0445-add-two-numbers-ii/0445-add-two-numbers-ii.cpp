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
    stack<int> st1, st2;
    ListNode *tp1 = l1;
    ListNode *tp2 = l2;

    while (tp1) {
      st1.push(tp1->val);
      tp1 = tp1->next;
    }
    while (tp2) {
      st2.push(tp2->val);
      tp2 = tp2->next;
    }

    ListNode *dummy = NULL;
    int carry = 0;

    while (!st1.empty() || !st2.empty()) {

      int a = 0, b = 0;
      if (!st1.empty()) {
        a = st1.top();
        st1.pop();
      }
      if (!st2.empty()) {
        b = st2.top();
        st2.pop();
      }
      int sum = a + b + carry;
      int finalNode = sum % 10;
      sum /= 10;
      carry = sum;

      ListNode *newNode = new ListNode(finalNode);
      newNode->next = dummy;
      dummy = newNode;
    }

    if (carry) {
      ListNode *newNode = new ListNode(carry);
      newNode->next = dummy;
      dummy = newNode;
    }

    return dummy;
  }
};