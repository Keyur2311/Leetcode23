class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = (int)height.size();

    int ans = 0, i = 0, j = n - 1;
    while (i < j) {
      int h = min(height[i], height[j]);
      ans = max(ans, (j - i) * h);
      while (i < j && height[i] <= h)
        i++;
      while (i < j && height[j] <= h)
        j--;
    }

    return ans;
  }
};