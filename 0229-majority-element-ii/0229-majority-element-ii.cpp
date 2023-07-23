class Solution {
public:
  vector<int> majorityElement(vector<int> &a) {
    int x = -1, y = -1, cx = 0, cy = 0;

    for (auto &val : a) {
      if (val == x)
        cx++;
      else if (val == y)
        cy++;
      else if (!cx)
        x = val, cx = 1;
      else if (!cy)
        y = val, cy = 1;
      else
        cx--, cy--;
    }

    cx = 0, cy = 0;

    for (auto &val : a) {
      if (val == x)
        cx++;
      else if (val == y)
        cy++;
    }

    int n = (int)a.size();

    vector<int> ans;
    if (cx > n / 3)
      ans.push_back(x);
    if (cy > n / 3)
      ans.push_back(y);

    return ans;
  }
};