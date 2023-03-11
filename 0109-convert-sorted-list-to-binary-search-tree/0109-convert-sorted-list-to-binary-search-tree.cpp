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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *construct(vector<int> arr, int lo, int hi)
   {
    if (lo > hi)
        return NULL;

    int mid = (lo + hi) / 2;
    TreeNode *node = new TreeNode(arr[mid]);
    node->left = construct(arr, lo, mid - 1);
    node->right = construct(arr, mid + 1, hi);

    return node;
   }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        if(temp==NULL) return NULL;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n = (int)arr.size();
        TreeNode* tnode = construct(arr,0,n-1);
        return tnode;
    }
};