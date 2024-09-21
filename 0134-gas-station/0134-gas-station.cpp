class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();

    int totgas = 0, totcost = 0, currgas = 0, ans = 0;

    for (int i = 0; i < n; i++) {
      totgas += gas[i];
      totcost += cost[i];

      currgas += (gas[i] - cost[i]);

      if (currgas < 0) {
        currgas = 0;
        ans = i + 1;
      }
    }

    if (totgas >= totcost)
      return ans;
    else
      return -1;
  }
};