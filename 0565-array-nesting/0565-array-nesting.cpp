class Solution {
public:
  struct DSU {
    vector<int> parent, size;
    int components = 0;

    DSU(int n = -1) {
      if (n >= 0)
        init(n);
    }

    void init(int n) {
      parent.resize(n + 1);
      size.assign(n + 1, 1);
      components = n;

      for (int i = 1; i <= n; i++)
        parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    void unite(int x, int y) {
      x = find(x);
      y = find(y);

      if (x != y) {
        if (size[x] < size[y])
          swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
      }
    }
  };
  int arrayNesting(vector<int> &nums) {
    int n = (int)nums.size();

    DSU d(n - 1);

    for (int i = 0; i < n; i++) {
      if (d.find(i) != d.find(nums[i]))
        d.unite(i, nums[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, d.size[i]);

    return ans;
  }
};