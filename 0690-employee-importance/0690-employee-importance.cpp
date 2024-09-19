/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/


class Solution {
public:
  map<int, int> idx;
  void solve(vector<Employee *> employees, int &sum, int i) {
    sum += employees[i]->importance;
    for (auto &subordinate : employees[i]->subordinates) {
      solve(employees, sum, idx[subordinate]);
    }
  }
  int getImportance(vector<Employee *> employees, int id) {

    int n = (int)employees.size();
    for (int i = 0; i < n; i++) {
      idx[employees[i]->id] = i;
    }
    int ans = 0;
    solve(employees, ans, idx[id]);
    return ans;
  }
};
