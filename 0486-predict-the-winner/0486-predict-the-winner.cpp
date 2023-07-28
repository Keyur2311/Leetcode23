
class Solution {
public:
  long long int solve(int i, int j, int turn, vector<int> &nums) {

    if (i > j)
      return 0;

    if (turn == 1)
      return max(nums[i] + solve(i + 1, j, 0, nums),
                 nums[j] + solve(i, j - 1, 0, nums));
    else
      return min(solve(i + 1, j, 1, nums), solve(i, j - 1, 1, nums));
  }

  bool PredictTheWinner(vector<int> &nums) {
    int n = (int)nums.size();
    long long int one = 0, two = 0;

    for (auto it : nums)
      two += it;

    one = solve(0, n - 1, 1, nums);
    two -= one;

    return one >= two;
  }
};