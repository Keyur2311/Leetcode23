class Solution {
public:
  struct DSU {
    vector<int> parent;
    int components = 0;

    DSU(int n = -1) {
      if (n >= 0)
        init(n);
    }

    void init(int n) {
      parent.resize(n + 1);
      components = n;

      for (int i = 0; i <= n; i++)
        parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool unite(int x, int y) {
      int rootx = find(x);
      int rooty = find(y);

      if (rooty != y || rootx == rooty)
        return false;

      parent[y] = x;
      components--;
      return true;
    }
  };
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    DSU d(n);

    for (int i = 0; i < n; i++) {

      int l = leftChild[i], r = rightChild[i];
      if (l >= 0 && !d.unite(i, l))
        return false;

      if (r >= 0 && !d.unite(i, r))
        return false;
    }

    return (bool)(d.components == 1);
  }
};