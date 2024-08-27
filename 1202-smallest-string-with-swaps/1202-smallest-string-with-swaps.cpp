class Solution {
public:
  void dfs(int src, string &s, string &currs, vector<int> &currv,
           vector<int> &vis, vector<int> adj[]) {
    vis[src] = 1;
    currs.push_back(s[src]);
    currv.push_back(src);

    for (auto child : adj[src]) {
      if (vis[child])
        continue;
      dfs(child, s, currs, currv, vis, adj);
    }
  }

  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = (int)s.size();
    int m = (int)pairs.size();

    vector<int> adj[n];

    for (auto &p : pairs) {
      int x = p[0];
      int y = p[1];
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    vector<string> vc;
    vector<vector<int>> vid;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
      if (vis[i])
        continue;
      string currs;
      vector<int> currv;
      dfs(i, s, currs, currv, vis, adj);
      vc.push_back(currs);
      vid.push_back(currv);
    }
      
    //  for (auto &val : vc)
    //   cout<<val<<endl;
    // // for (auto &val : vid)
    // //   sort(val.begin(), val.end());


    for (auto &val : vc)
      sort(val.begin(), val.end());
    for (auto &val : vid)
      sort(val.begin(), val.end());

    string ans = s;
    for (int i = 0; i < (int)vc.size(); i++) {
      int len = (int)vc[i].size();
      for (int j = 0; j < len; j++)
        ans[vid[i][j]] = vc[i][j];
    }
    return ans;
  }
};