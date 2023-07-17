class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int c = -1, votes = 0;
    for (auto val : nums) {
      if (votes == 0) {
        votes = 1;
        c = val;
      } else {
        if (val == c)
          votes++;
        else
          votes--;
      }
    }

    return c;
  }
};