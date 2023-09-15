class Solution {
public:
  struct DSU {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    DSU(int n = -1) {
      if (n >= 0)
        init(n);
    }

    void init(int n) {
      parent.resize(n + 1);
      size.assign(n + 1, 1);
      components = n;

      for (int i = 0; i <= n; i++)
        parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool unite(int x, int y) {
      x = find(x);
      y = find(y);

      if (x == y)
        return false;

      if (x > y)
        swap(x, y);

      parent[y] = x;
      size[x] += size[y];
      components--;
      return true;
    }
  };

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = (int)s1.size();
    DSU d(26);

    for (int i = 0; i < n; i++) {
      int u = s1[i] - 'a', v = s2[i] - 'a';
      if (d.find(u) == d.find(v))
        continue;
      d.unite(u, v);
    }

    for (auto &ch : baseStr) {
      int u = ch - 'a';
      for (int i = 0; i < 26; i++) {
        if (d.find(u) == d.find(i)) {
          ch = (char)(i + 'a');
          break;
        }
      }
    }

    return baseStr;
  }
};
