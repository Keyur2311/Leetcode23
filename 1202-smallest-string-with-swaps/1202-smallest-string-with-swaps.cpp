// approach 1 : with dfs
// class Solution {
// public:
//   void dfs(int src, string &s, string &currs, vector<int> &currv,
//            vector<int> &vis, vector<int> adj[]) {
//     vis[src] = 1;
//     currs.push_back(s[src]);
//     currv.push_back(src);

//     for (auto child : adj[src]) {
//       if (vis[child])
//         continue;
//       dfs(child, s, currs, currv, vis, adj);
//     }
//   }

//   string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
//     int n = (int)s.size();
//     int m = (int)pairs.size();

//     vector<int> adj[n];

//     for (auto &p : pairs) {
//       int x = p[0];
//       int y = p[1];
//       adj[x].push_back(y);
//       adj[y].push_back(x);
//     }

//     vector<string> vc;
//     vector<vector<int>> vid;
//     vector<int> vis(n, 0);

//     for (int i = 0; i < n; i++) {
//       if (vis[i])
//         continue;
//       string currs;
//       vector<int> currv;
//       dfs(i, s, currs, currv, vis, adj);
//       vc.push_back(currs);
//       vid.push_back(currv);
//     }

//     for (auto &val : vc)
//       sort(val.begin(), val.end());
//     for (auto &val : vid)
//       sort(val.begin(), val.end());

//     string ans = s;
//     for (int i = 0; i < (int)vc.size(); i++) {
//       int len = (int)vc[i].size();
//       for (int j = 0; j < len; j++)
//         ans[vid[i][j]] = vc[i][j];
//     }
//     return ans;
//   }
// };

// approach 2: with DSU
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
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = (int)s.size();
    int m = (int)pairs.size();

    vector<vector<int>> v(n);

    DSU d(n);
    for (auto &p : pairs) {
      int x = p[0], y = p[1];
      if (d.find(x) != d.find(y))
        d.unite(x, y);
    }

    for (int i = 0; i < n; i++)
      v[d.find(i)].push_back(i);

    string ans = s;
    for (auto &vec : v) {
      string ss;
      for (auto &val : vec)
        ss.push_back(s[val]);
      sort(ss.begin(), ss.end());

      for (int i = 0; i < vec.size(); i++)
        ans[vec[i]] = ss[i];
    }
    return ans;
  }
};