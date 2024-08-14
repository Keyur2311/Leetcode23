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
    vector<int> v;
    ListNode *curr = head;
    while (curr) {
      v.push_back(curr->val);
      curr = curr->next;
    }

    while (true) {
      int n = (int)v.size();

      unordered_map<int, int> mp;
      mp[0] = -1;
      set<int> delIdx;

      int sum = 0;
      bool ok = false;

      for (int i = 0; i < n; i++) {
        sum += v[i];
        if (mp.find(sum) != mp.end()) {
          int l = mp[sum] += 1;
          int r = i;
          for (int j = l; j <= r; j++)
            delIdx.insert(j);
          ok = true;
          break;
        }
        mp[sum] = i;
      }

      vector<int> temp;
      for (int i = 0; i < n; i++) {
        if (delIdx.count(i))
          continue;
        temp.push_back(v[i]);
      }
        
      v = temp;
        if (!ok)
          break;
    }

    if (v.empty())
      return NULL;

    ListNode *newNode = new ListNode(v[0]);
    ListNode *temp = newNode;
 
    for (int i = 1; i < (int)v.size(); i++) {
      temp->next = new ListNode(v[i]);
      temp = temp->next;
    }
    return newNode;
  }
};