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
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
      set<int> st(nums.begin(), nums.end());

      ListNode temp(0);
      temp.next = head;
      ListNode *cr = &temp;

      while (cr->next) {
        if (st.find(cr->next->val) != st.end()) {
          ListNode *nd = cr->next;
          cr->next = cr->next->next;
          delete nd;
        } else 
          cr = cr->next;
        
      }

      return temp.next;
    }
  };