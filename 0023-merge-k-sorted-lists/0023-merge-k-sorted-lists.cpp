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
  class cmp {
  public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

    for (int i = 0; i < (int)lists.size(); i++)
       if (lists[i] != NULL)
        pq.push(lists[i]);

    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    while (!pq.empty()) {
      ListNode *curr = pq.top();
      pq.pop();

      tail->next = curr;
      tail = curr;

      if (curr->next)
        pq.push(curr->next);
    }
    return dummy->next;
  }
};
