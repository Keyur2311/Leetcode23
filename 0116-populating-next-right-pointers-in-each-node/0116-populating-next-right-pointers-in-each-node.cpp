/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//approach 1 : using zero extra space
class Solution {
public:
  Node *connect(Node *root) {
    if (root == NULL)
      return NULL;

    Node *prev = root, *curr;
    while (prev) {
      curr = prev;
      while (curr && curr->left) {
        curr->left->next = curr->right;
        if (curr->next)
          curr->right->next = curr->next->left;
        curr = curr->next;
      }
      prev = prev->left;
    }
    
    return root;
  }
};
 
//approach 2 : using level order traversal (extra space)
// class Solution {
// public:
//   Node *connect(Node *root) {
//     if (root == NULL)
//       return NULL;

//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty()) {
//       int n = q.size();
//       for (int i = 1; i <= n; i++) {

//         Node *curr = q.front();
//         q.pop();

//         if (i != n) 
//           curr->next = q.front();

//         if (curr->left)
//           q.push(curr->left);
//         if (curr->right)
//           q.push(curr->right);
//       }
//     }

//     return root;
//   }
// };

