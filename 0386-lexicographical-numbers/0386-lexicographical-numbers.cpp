//approach 1 (nlogn and with extra space)
// class Solution {
// public:
//   vector<int> lexicalOrder(int n) {

//     vector<string> v;
//     for (int i = 1; i <= n; i++)
//       v.push_back(to_string(i));

//     sort(v.begin(), v.end());

//     vector<int> ans;
//     for (auto &it : v)
//       ans.push_back(stoi(it));

//     return ans;
//   }
// };
//approach 2 :- recursion o(n)
class Solution {
public:
  void solve(int i, int n, vector<int> &ans) {
    if (i > n)
      return;

    int curr = i;
    ans.push_back(curr);
    for (int i = 0; i <= 9; i++) {
      int temp = curr * 10 + i;
      solve(temp, n, ans);
    }
  }
  vector<int> lexicalOrder(int n) {

    vector<int> ans;
    for (int i = 1; i <= 9; i++)
      solve(i, n, ans);
    return ans;
  }
};