struct DSU {
  vector<int> parent, size;
  int components = 0;

  DSU(int n = -1) {
    if (n >= 0)
      init(n);
  }

  void init(int n) {
    parent.resize(n);
    size.assign(n, 1);
    components = n;

    for (int i = 0; i < n; i++)
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
class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    int n = (int)stones.size();

    DSU d(n);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (((stones[i][0] == stones[j][0]) ||
             (stones[i][1] == stones[j][1])) &&
            d.find(i) != d.find(j))
          d.unite(i, j);
      }
    }

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
      v[d.find(i)]++;

    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += (v[i] >= 1 ? v[i] - 1 : 0);

    return ans;
  }
};