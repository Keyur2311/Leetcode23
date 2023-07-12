class Solution {
public:
  bool DFS(int source, vector<bool> &visited, vector<bool> &currVisited,
           vector<vector<int>> &graph) {
    visited[source] = true;
    currVisited[source] = true;

    for (auto adj : graph[source]) {
      if (visited[adj] == false) {
        if (DFS(adj, visited, currVisited, graph)) {
          return true;
        }
      }

      else if (visited[adj] == true && currVisited[adj] == true) 
        return true;
      
    }

    currVisited[source] = false;
    return false;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    vector<bool> currVisited(vertices, false);

    for (int i = 0; i < vertices; i++) {
      if (visited[i] == false) {
        DFS(i, visited, currVisited, graph);
      }
    }
      
    vector<int> ans;
    for (int i = 0; i < vertices; i++) {
      if (!currVisited[i])
        ans.push_back(i);
    }
    return ans;
  }
};